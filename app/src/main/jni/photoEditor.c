#include <jni.h>
JNIEXPORT void JNICALL
Java_com_example_photoeditor_MainActivity_blackAndWhite(JNIEnv *env,jclass type,jintArray pixels_, jint width,jint height) {

    jint *pixels = (*env)->GetIntArrayElements(env,pixels_,NULL);
    char *colors = (char *) pixels;
    int pixelCount = width*height*4;
    int i = 0;
    while(i < pixelCount){
        unsigned char average = (colors[i] + colors[i+1] + colors[i+2])/3;
        if(average > 155)
        {
            average = 255;
        }
        else
        {
            average = 0;
        }
        colors[i] = average;
        colors[i+1] = average;
        colors[i+2] = average;
        i += 4 ;
    }

    (*env)->ReleaseIntArrayElements(env, pixels_,pixels,0);
}