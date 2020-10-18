from threading import *
import threading

count=0
mutex=threading.Semaphore()
db=threading.Semaphore()


def reader(i):
    global count
    mutex.acquire()
    count = count + 1
    if (count == 1):
        db.acquire()
    mutex.release()
    print("reader reads", i)
    mutex.acquire()
    count = count - 1
    if (count == 0):
        db.release()
    mutex.release()

def writer(i):
    db.acquire()
    print("writer write",i)
    db.release()

class read(Thread):
    def run(self):
        for i in range(15):
            reader(i)

class write(Thread):
    def run(self):
        for j in range(15):
            writer(j)

t0=write()
t1=read()
t2=write()
t3=read()
t4=write()
t5=read()
t6=write()
t7=read()
t8=write()
t9=read()


t0.start()
t1.start()
t3.start()
t4.start()
t6.start()
t5.start()
t2.start()
t8.start()
t7.start()
t9.start()