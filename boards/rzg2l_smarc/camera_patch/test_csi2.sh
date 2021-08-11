#!/bin/bash
media-ctl -d /dev/media0 -r
media-ctl -d /dev/media0 -l "'rzg2l_csi2 10830400.csi2':1 -> 'CRU output':0 [1]"
media-ctl -d /dev/media0 -V "'rzg2l_csi2 10830400.csi2':1 [fmt:UYVY8_2X8/$1 field:none]"
media-ctl -d /dev/media0 -V "'ov5645 0-003c':0 [fmt:UYVY8_2X8/$1 field:none]"
gst-launch-1.0 v4l2src device=/dev/video0 ! videoconvert ! waylandsink
