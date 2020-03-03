/*
  Sync_cameras
  This file takes the left and right camera images and information and copies the time stamp obtained from the info
  of left image onto right image. Then publishes the synced images.
*/

#include <include/sync_images.hxx>

#include <cv_bridge/cv_bridge.h>
#include <opencv2/highgui/highgui.hpp>


#include <image_transport/image_transport.h>

#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>

#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <sensor_msgs/Image.h>

using namespace message_filters;
using namespace sensor_msgs;



void camera_sync_publisher::ImageCB(const CameraInfoConstPtr& RightInfo,const ImageConstPtr& RightImage,const CameraInfoConstPtr& LeftInfo, const ImageConstPtr& LeftImage)
{
  // Debug message
  printf("The Image synchronizer callback is hit \n");

  ROS_INFO("Call Back fcn called");

  CameraInfo LeftCameraInfo = *LeftInfo;
  CameraInfo RightCameraInfo = *RightInfo;

  Image RightCameraImage = *RightImage;

  // Copy the header stamp from left image onto right image
  RightCameraImage.header.stamp = LeftImage->header.stamp;

  // Update the info header from image
  LeftCameraInfo.header = LeftImage->header;
  LeftCameraInfo.header.frame_id = "roboname/left_camera_link";

  // Update the info from image
  RightCameraInfo.header = RightImage->header;
  RightCameraInfo.header.stamp = RightImage->header.stamp;
  RightCameraInfo.header.frame_id = "roboname/right_camera_link";

  // Publish the updated information
  // Create an Image transport object for publishing

  // Right camera publishing
  rightCameraInfoPub.publish(RightCameraInfo);
  rightImageSyncPub.publish(RightCameraImage);

  // Left camera publishing
  leftCameraInfoPub.publish(LeftCameraInfo);
  leftImageSyncPub.publish(*LeftImage);

  return;
}

void camera_sync_publisher::Run(void)
{
  // Right Camera subscription
  //    /roboname/right_camera_unsync/camera_info
  //    /roboname/right_camera_unsync/image_raw
  message_filters::Subscriber<sensor_msgs::CameraInfo> rightCameraInfoSub(m_nh, "/roboname/right_camera_unsync/camera_info", 1);
  message_filters::Subscriber<sensor_msgs::Image> rightCameraImageRawSub(m_nh, "/roboname/right_camera_unsync/image_raw", 1);

  // Left Camera subscription
  //    /roboname/left_camera_unsync/camera_info
  //    /roboname/left_camera_unsync/image_raw
  message_filters::Subscriber<sensor_msgs::CameraInfo> leftCameraInfoSub(m_nh, "/roboname/left_camera_unsync/camera_info", 1);
  message_filters::Subscriber<sensor_msgs::Image> leftCameraImageRawSub(m_nh, "/roboname/left_camera_unsync/image_raw", 1);


  typedef sync_policies::ApproximateTime<CameraInfo, Image, CameraInfo, Image> MySyncPolicy;
  // ApproximateTime takes a queue size as its constructor argument, hence MySyncPolicy(10)
  Synchronizer<MySyncPolicy> sync(MySyncPolicy(10), rightCameraInfoSub, rightCameraImageRawSub, leftCameraInfoSub, leftCameraImageRawSub);
  //TimeSynchronizer<CameraInfo, Image, CameraInfo, Image> sync(rightCameraInfoSub, rightCameraImageRawSub, leftCameraInfoSub, leftCameraImageRawSub, 10);
  sync.registerCallback(boost::bind(&camera_sync_publisher::ImageCB, this, _1, _2, _3, _4));

  ros::spin();

  return;
}


int main(int argc, char** argv)
{
    //ros::NodeHandle nh("");
    ros::init(argc, argv, "sync_images");
    camera_sync_publisher CameraSync;
    CameraSync.Run();

    return 0;
}