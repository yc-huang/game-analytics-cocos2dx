#include "TDCCVirtualCurrency.h"
#include "TDGAJniHelper.h"
#include "TDGALog.h"

#define JAVA_CLASS_NAME "com.tendcloud.tenddata.TDGAVirtualCurrency"

void TDCCVirtualCurrency::onChargeRequst(const char* orderId, const char* iapId, double currencyAmount, const char* currencyType, double virtualCurrencyAmount, const char* paymentType) {
	TDGAJniMethodInfo t;
	if (TDGAJniHelper::getStaticMethodInfo(t
		, JAVA_CLASS_NAME
		, "onChargeRequest"
		, "(Ljava/lang/String;Ljava/lang/String;DLjava/lang/String;DLjava/lang/String;)V")) {
		jstring jorderId = t.env->NewStringUTF(orderId);
		jstring jiapId = t.env->NewStringUTF(iapId);
		jstring jcurrencyType = t.env->NewStringUTF(currencyType);
		jstring jpaymentType = t.env->NewStringUTF(paymentType);
		t.env->CallStaticVoidMethod(t.classID, t.methodID, jorderId, jiapId, currencyAmount, jcurrencyType, virtualCurrencyAmount, jpaymentType);
		t.env->DeleteLocalRef(jorderId);
		t.env->DeleteLocalRef(jiapId);
		t.env->DeleteLocalRef(jcurrencyType);
		t.env->DeleteLocalRef(jpaymentType);
		t.env->DeleteLocalRef(t.classID);
	}
}
    
void TDCCVirtualCurrency::onChargeSuccess(const char* orderId) {
	TDGAJniMethodInfo t;
	if (TDGAJniHelper::getStaticMethodInfo(t
		, JAVA_CLASS_NAME
		, "onChargeSuccess"
		, "(Ljava/lang/String;)V")) {
		jstring jorderId = t.env->NewStringUTF(orderId);
		t.env->CallStaticVoidMethod(t.classID, t.methodID, jorderId);
		t.env->DeleteLocalRef(jorderId);
		t.env->DeleteLocalRef(t.classID);
	}
}

void TDCCVirtualCurrency::onReward(double currencyAmount, const char* reason) {
	TDGAJniMethodInfo t;
	if (TDGAJniHelper::getStaticMethodInfo(t
		, JAVA_CLASS_NAME
		, "onReward"
		, "(DLjava/lang/String;)V")) {
		jstring jreason = t.env->NewStringUTF(reason);
		t.env->CallStaticVoidMethod(t.classID, t.methodID, currencyAmount, jreason);
		t.env->DeleteLocalRef(jreason);
		t.env->DeleteLocalRef(t.classID);
	}
}
