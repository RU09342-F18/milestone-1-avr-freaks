#!/bin/bash

stime=0.01;

	echo -n -e "\x03 \xFF \x00 \x00 \x0D" >> /dev/ttyUSB0;
	sleep $stime;
	echo -n -e "\x03 \x00 \xFF \x00 \x0D" >> /dev/ttyUSB0;
	sleep $stime;
	echo -n -e "\x03 \x00 \x00 \xFF \x0D" >> /dev/ttyUSB0;
	sleep $stime;
	
	echo -n -e "\x03 \xFF \x00 \x00 \x0D" >> /dev/ttyUSB0;
	sleep $stime;
	echo -n -e "\x03 \x00 \xFF \x00 \x0D" >> /dev/ttyUSB0;
	sleep $stime;
	echo -n -e "\x03 \x00 \x00 \xFF \x0D" >> /dev/ttyUSB0;
	sleep $stime;
	
	echo -n -e "\x03 \xFF \x00 \x00 \x0D" >> /dev/ttyUSB0;
	sleep $stime;
	echo -n -e "\x03 \x00 \xFF \x00 \x0D" >> /dev/ttyUSB0;
	sleep $stime;
	echo -n -e "\x03 \x00 \x00 \xFF \x0D" >> /dev/ttyUSB0;
	sleep $stime;



	echo -n -e "\x03 \x00 \x00 \x00 \x0D" >> /dev/ttyUSB0;
