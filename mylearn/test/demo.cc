#include <glog/logging.h>

int main(int argc,char* argv[])
{
    // 设置输出到./log位置，如果不加的话默认输出到/tmp
    // 如果想输出到屏幕的话 不需要初始化库，直接LOG(INFO)即可
    FLAGS_log_dir = "./bin";

    // 初始化glog库
    google::InitGoogleLogging(argv[0]);
    // 输出log为 Hello,GLOG!
    LOG(INFO) << "Hello,GLOG!";

    // 关闭库
    google::ShutdownGoogleLogging();
}
