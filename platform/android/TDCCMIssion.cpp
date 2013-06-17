#include "TDCCMission.h"
#include "TDGAJniHelper.h"
#include "TDGALog.h"

#define JAVA_CLASS_NAME "com.tendcloud.tenddata.TDGAMission"

void TDCCMission::onBegin(const char* missionId) {
	TDGAJniMethodInfo t;
	if (TDGAJniHelper::getStaticMethodInfo(t
		, JAVA_CLASS_NAME
		, "onBegin"
		, "(Ljava/lang/String;)V")) {
		jstring jmissionId = t.env->NewStringUTF(missionId);
		t.env->CallStaticVoidMethod(t.classID, t.methodID, jmissionId);
		t.env->DeleteLocalRef(jmissionId);
		t.env->DeleteLocalRef(t.classID);
	}
}
    
void TDCCMission::onCompleted(const char* missionId) {
	TDGAJniMethodInfo t;
	if (TDGAJniHelper::getStaticMethodInfo(t
		, JAVA_CLASS_NAME
		, "onCompleted"
		, "(Ljava/lang/String;)V")) {
		jstring jmissionId = t.env->NewStringUTF(missionId);
		t.env->CallStaticVoidMethod(t.classID, t.methodID, jmissionId);
		t.env->DeleteLocalRef(jmissionId);
		t.env->DeleteLocalRef(t.classID);
	}
}

void TDCCMission::onFailed(const char* missionId, const char* failedCause) {
	TDGAJniMethodInfo t;
	if (TDGAJniHelper::getStaticMethodInfo(t
		, JAVA_CLASS_NAME
		, "onFailed"
		, "(Ljava/lang/String;Ljava/lang/String;)V")) {
		jstring jmissionId = t.env->NewStringUTF(missionId);
		jstring jfailedCause = t.env->NewStringUTF(failedCause);
		t.env->CallStaticVoidMethod(t.classID, t.methodID, jmissionId, jfailedCause);
		t.env->DeleteLocalRef(jmissionId);
		t.env->DeleteLocalRef(jfailedCause);
		t.env->DeleteLocalRef(t.classID);
	}
}
