./compile.sh
HOST=192.168.0.99
ftp-upload -h ${HOST} -u root --password ismart12 -d /system/sdcard mJpegStreamer
ftp-upload -h ${HOST} -u root --password ismart12 -d /system/sdcard h264streamer