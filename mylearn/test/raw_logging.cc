#define GLOG_CUSTOM_PREFIX_SUPPORT
#include <glog/logging.h>
#include <glog/raw_logging.h>

/**
 * cmake -S . -B build
 * cmake --build build
 * GLOG_logtostderr=1 ./build/basic
 */

/* This function writes a prefix that matches glog's default format.
 * (The third parameter can be used to receive user-supplied data, and is
 * NULL by default.)
 */
// void CustomPrefix(std::ostream &s, const LogMessageInfo &l, void* param) {
//   s << "[CustomPrefix][" << (intptr_t)param << "]";
// }

intptr_t param = 10;

int main(int argc, char* argv[]) {
    // Initialize Google’s logging library.
    // 有bug
    // google::InitGoogleLogging(argv[0], &CustomPrefix, reinterpret_cast<void*>(param));
    google::InitGoogleLogging(argv[0]);
    int num_cookies = 3;

    // ...
    LOG(INFO) << "Found " << num_cookies << " cookies";

    google::ShutdownGoogleLogging();
}
