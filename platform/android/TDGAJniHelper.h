#ifndef __TDGA_JNI_HELPER_H__
#define __TDGA_JNI_HELPER_H__

#include <jni.h>
#include <string>


typedef struct TDGAJniMethodInfo_ {
    JNIEnv *    env;
    jclass      classID;
    jmethodID   methodID;
} TDGAJniMethodInfo;

class TDGAJniHelper {
public:
	static bool getJNIEnv(JNIEnv **env);
    static JavaVM* getJavaVM();
    static void setJavaVM(JavaVM *javaVM);
    static const char* getExternalAssetPath();
    static void setExternalAssetPath(const char* externalAssetPath);
    static jclass getClassID(const char *className, JNIEnv *env=0);
    static bool getStaticMethodInfo(TDGAJniMethodInfo &methodinfo, const char *className, const char *methodName, const char *paramCode);
    static bool getMethodInfo      (TDGAJniMethodInfo &methodinfo, const char *className, const char *methodName, const char *paramCode);
    static std::string jstring2string(jstring str);

private:
    static JavaVM *m_psJavaVM;
    static std::string m_externalAssetPath;
};

#endif // __TDGA_JNI_HELPER_H__
