kill_process
============

Extending Python 3 with Assembly Language and C Sample Code. Tested on Fedora 32. Take note that this will only works on a 64 bit Linux machines.

Install Dependency (Fedora)
===========================
::

    yum install nasm

Building and Installing
=======================
::

	./setup.py build install

Installing Through PyPi
=======================
::

	pip install kill_process

Python Sample Usage
===================
::

	import kill_process
	kill_process.kill(12345)
