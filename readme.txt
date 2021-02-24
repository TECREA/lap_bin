CAMKIT source files

/src contains the sources of every CAMKIT background applications, contents of this folder should be reside in the "/home/pi/NetbeansProjects" of the target 
/etc has the rc.local init file 
/home has the output files, and the contents of "/home/user" should be inside "/home/pi"
/tcp_com_test its a simple c project to check the incoming ack frames from the artimo server (its not required for the firmware)

- crontab.txt has the entries of the cron Scheduler
- firmware_image.gz its the latest image of the SOM memory(including the <boot> and <root> partitions). 
(image should be decompressed using the right tool)