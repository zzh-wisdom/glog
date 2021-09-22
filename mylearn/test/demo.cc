#include <glog/logging.h>
// #include <glog/vlog_is_on.h>
#include <assert.h>

int main(int argc,char* argv[])
{
    // 设置输出到./log位置，如果不加的话默认输出到/tmp
    // 如果想输出到屏幕的话 不需要初始化库，直接LOG(INFO)即可
    // FLAGS_log_dir = "./bin";
    FLAGS_logtostderr = 1;
    FLAGS_v = 1;

    // 初始化glog库
    google::InitGoogleLogging(argv[0]);
    // 输出log为 Hello,GLOG!
    LOG(INFO) << "Hello,GLOG!";

#if DCHECK_IS_ON()
    printf("debug\n");
#else
    printf("no debug\n");
#endif

    DLOG(ERROR) << "DLOG!";
    DLOG(WARNING) << "DLOG!";
    DLOG(INFO) << "DLOG!";
    
    assert(1);
    // PLOG(ERROR) << "error";  // NDEBUG 模式下会编译错误
    DVLOG(1) << "I’m printed when you run the program with --v=1 or higher";
    DVLOG(2) << "I’m printed when you run the program with --v=2 or higher";
    
    DLOG_ASSERT(0);
    // 关闭库
    google::ShutdownGoogleLogging();
}
