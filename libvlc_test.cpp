#include "vlc_reader.h"

int main01()
{
	vlc_reader r("rtsp://admin:admin12345@168.1.3.64:554/Streaming/Channels/101?transportmode=unicast");
	int rtsp_w = 640, rtsp_h = 480;
	r.start(rtsp_w, rtsp_h);
	while (1)
	{
		cv::Mat frame = r.frame();
		if (!frame.empty())
		{
			imshow("test", frame);
			int ch = cv::waitKey(1);
			if (ch > 0)
				break;
		}
	}
	return 0;
}
