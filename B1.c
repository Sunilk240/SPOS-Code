#include<jni.h>
#include<stdio.h>
#include"B1.h"

JNIEXPORT int JNICALL  JAVA_B1_add(JNIEnv *env, jobject obj, jint a, jint b){
    print(f"%d + %d = %d "a,b,(a+b));
    return 0;
}

Steps to execute the program -------------------->
 javac -h . B1.java
(base) admin1@408-21:~$ javac B1.java
(base) admin1@408-21:~$ javah B1
(base) admin1@408-21:~$  gcc -fPIC -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -shared -o libb1.so B1.c
(base) admin1@408-21:~$ java -Djava.library.path=. B1
