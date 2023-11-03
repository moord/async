#include "async.h"
#include "bulk.h"

ConsoleLog logger;
FileLog saver;

namespace async {

handle_t connect(std::size_t bulk) {
    auto statBulk = std::make_shared<cBulk>(BulkTypeSize::STATIC_SIZE);

    statBulk->Subscribe(&logger);
    statBulk->Subscribe(&saver);

    auto dynBulk = std::make_shared<cBulk>(BulkTypeSize::DYNAMIC_SIZE);

    dynBulk->Subscribe(&logger);
    dynBulk->Subscribe(&saver);

    return new DataProcessor(bulk, dynBulk, statBulk);
}

void receive(handle_t handle, const char *data, std::size_t size) {
    if( handle != nullptr ){
        static_cast<DataProcessor*>(handle)->Get(data,size);
    }
}

void disconnect(handle_t handle) {
    delete static_cast<DataProcessor*>(handle);
    handle = nullptr;
}

}
