#!/bin/bash

sleep 2
cd /
cd home/shunia/Desktop/UXP\ Project/src/client
if ./client output 10 int:$i >> /home/shunia/Desktop/UXP\ Project/src/bash_tests/logs/log_client.txt;
then
echo "Success"
else
echo "Failed"
fi
done

