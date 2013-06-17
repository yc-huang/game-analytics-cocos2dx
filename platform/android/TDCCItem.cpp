#include "TDCCItem.h"
#include "TDGAJniHelper.h"
#include "TDGALog.h"

#define JAVA_CLASS_NAME "com.tendcloud.tenddata.TDGAItem"

void TDCCItem::onPurchase(const char* item, int number, double price) {
	TDGAJniMethodInfo t;
	if (TDGAJniHelper::getStaticMethodInfo(t
		, JAVA_CLASS_NAME
		, "onPurchase"
		, "(Ljava/lang/String;ID)V")) {
		jstring jitem = t.env->NewStringUTF(item);
		t.env->CallStaticVoidMethod(t.classID, t.methodID, jitem, number, price);
		t.env->DeleteLocalRef(jitem);
		t.env->DeleteLocalRef(t.classID);
	}
}
    
void TDCCItem::onUse(const char* item, int number) {
	TDGAJniMethodInfo t;
	if (TDGAJniHelper::getStaticMethodInfo(t
		, JAVA_CLASS_NAME
		, "onUse"
		, "(Ljava/lang/String;I)V")) {
		jstring jitem = t.env->NewStringUTF(item);
		t.env->CallStaticVoidMethod(t.classID, t.methodID, jitem, number);
		t.env->DeleteLocalRef(jitem);
		t.env->DeleteLocalRef(t.classID);
	}
}
