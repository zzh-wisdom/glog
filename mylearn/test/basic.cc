#include <glog/logging.h>

/**
 * cmake -S . -B build
 * cmake --build build
 * GLOG_logtostderr=1 ./build/basic
 */
int main(int argc, char* argv[]) {
    // Initialize Google’s logging library.
    google::InitGoogleLogging(argv[0]);
    int num_cookies = 3;

    // ...
    LOG(INFO) << "Found " << num_cookies << " cookies";

    google::ShutdownGoogleLogging();
}
