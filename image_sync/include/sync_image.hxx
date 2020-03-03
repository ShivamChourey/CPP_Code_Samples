#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/CameraInfo.h>

#include <image_transport/image_transport.h>

#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>

using namespace message_filters;
using namespace sensor_msgs;


class camera_sync_publisher
{
public:

  camera_sync_publisher()
  {
    image_transport::ImageTransport it(m_nh);
    rightCameraInfoPub = m_nh.advertise<sensor_msgs::CameraInfo>("right/camera_info", 10);
    rightImageSyncPub = it.advertise("right_image_sync", 10);
    leftCameraInfoPub = m_nh.advertise<sensor_msgs::CameraInfo>("left/camera_info", 10);
    leftImageSyncPub = it.advertise("left_image_sync", 10);
  }

  void ImageCB(const CameraInfoConstPtr& RightInfo,const ImageConstPtr& RightImage,const CameraInfoConstPtr& LeftInfo, const ImageConstPtr& LeftImage);
  void Run(void);

protected:
  ros::NodeHandle m_nh;
  ros::Publisher rightCameraInfoPub;
  ros::Publisher leftCameraInfoPub;
  image_transport:: Publisher leftImageSyncPub;
  image_transport:: Publisher rightImageSyncPub;

};