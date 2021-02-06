# opencv 安装说明
**1、首先下载opencv-4.5.1-vc14-vc15.exe**

**2、安装后配置用户环境变量**

**3、在项目属性中分别添加vc++目录的include Directorie：~\opencv\build\include和Library Directories:~\opencv\build\x64\vc15\lib**

**4、链接器中添加opencv_world451d.lib**

**5、添加库函数声明：**
```
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
```
**6、调用资源文件时，可以将文件直接复制到项目中**