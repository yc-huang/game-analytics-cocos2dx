#include "TDCCAccount.h"
#include "TDGAJniHelper.h"
#include "TDGALog.h"

#define JAVA_CLASS_NAME "com.tendcloud.tenddata.TDGAAccount"
#define JAVA_CLASS_ACCOUNT_TYPE "com.tendcloud.tenddata.TDGAAccount$AccountType"
#define JAVA_CLASS_GENDER "com.tendcloud.tenddata.TDGAAccount$Gender"

static const char * TDCCAccountTypeString[] = {
			"ANONYMOUS",
			"REGISTERED",
			"SINA_WEIBO",
			"QQ",
			"QQ_WEIBO",
			"ND91",
			"", "", "", "", "",
			"TYPE11",
			"TYPE12",
			"TYPE13",
			"TYPE14",
			"TYPE15",
			"TYPE16",
			"TYPE17",
			"TYPE18",
			"TYPE19",
			"TYPE20"
};

static const char * TDCCGenderString[] = {
			"UNKNOW",
			"MALE",
			"FEMALE"
};

TDCCAccount::TDCCAccount():mAccount(NULL) {
	LOGD("TDCCAccount()");
}

TDCCAccount::~TDCCAccount() {
	LOGD("~TDCCAccount()");
	JNIEnv *env = 0;
	if (mAccount && TDGAJniHelper::getJNIEnv(&env)) {
		env->DeleteGlobalRef((jobject)mAccount);
		mAccount == NULL;
	}
}

TDCCAccount* TDCCAccount::setAccount(const char* accountId) {
    if (NULL == accountId || strlen(accountId) == 0) {
        return NULL;
    }
    static TDCCAccount account;
    TDGAJniMethodInfo t;
	if (TDGAJniHelper::getStaticMethodInfo(t
		, JAVA_CLASS_NAME
		, "setAccount"
		, "(Ljava/lang/String;)Lcom/tendcloud/tenddata/TDGAAccount;")) {
		if (account.mAccount) {
			t.env->DeleteGlobalRef((jobject)account.mAccount);
			account.mAccount == NULL;
		}

		jstring jaccountId = t.env->NewStringUTF(accountId);
		jobject jobj = t.env->CallStaticObjectMethod(t.classID, t.methodID, jaccountId);
		account.mAccount = (void*)t.env->NewGlobalRef(jobj);
		t.env->DeleteLocalRef(jaccountId);
		t.env->DeleteLocalRef(jobj);
		t.env->DeleteLocalRef(t.classID);
	}

    return &account;
}

void TDCCAccount::setAccountName(const char* accountName) {
	TDGAJniMethodInfo t;
	if (mAccount && TDGAJniHelper::getMethodInfo(t
		, JAVA_CLASS_NAME
		, "setAccountName"
		, "(Ljava/lang/String;)V")) {
		jstring jaccountName = t.env->NewStringUTF(accountName);
		t.env->CallVoidMethod((jobject)mAccount, t.methodID, jaccountName);
		t.env->DeleteLocalRef(jaccountName);
		t.env->DeleteLocalRef(t.classID);
	}
}

void TDCCAccount::setGameServer(const char* gameServer) {
	TDGAJniMethodInfo t;
	if (mAccount && TDGAJniHelper::getMethodInfo(t
		, JAVA_CLASS_NAME
		, "setGameServer"
		, "(Ljava/lang/String;)V")) {
		jstring jgameServer = t.env->NewStringUTF(gameServer);
		t.env->CallVoidMethod((jobject)mAccount, t.methodID, jgameServer);
		t.env->DeleteLocalRef(jgameServer);
		t.env->DeleteLocalRef(t.classID);
	}
}

void TDCCAccount::setLevel(int level) {
	TDGAJniMethodInfo t;
	if (mAccount && TDGAJniHelper::getMethodInfo(t
		, JAVA_CLASS_NAME
		, "setLevel"
		, "(I)V")) {
		t.env->CallVoidMethod((jobject)mAccount, t.methodID, level);
		t.env->DeleteLocalRef(t.classID);
	}
}

void TDCCAccount::setAge(int age) {
	TDGAJniMethodInfo t;
	if (mAccount && TDGAJniHelper::getMethodInfo(t
		, JAVA_CLASS_NAME
		, "setAge"
		, "(I)V")) {
		t.env->CallVoidMethod((jobject)mAccount, t.methodID, age);
		t.env->DeleteLocalRef(t.classID);
	}
}

void TDCCAccount::setAccountType(TDCCAccountType accountType) {
	TDGAJniMethodInfo t;
	TDGAJniMethodInfo type;
	if (mAccount && TDGAJniHelper::getMethodInfo(t
		, JAVA_CLASS_NAME
		, "setAccountType"
		, "(Lcom/tendcloud/tenddata/TDGAAccount$AccountType;)V") &&
		TDGAJniHelper::getStaticMethodInfo(type
		, JAVA_CLASS_ACCOUNT_TYPE
		, "valueOf"
		, "(Ljava/lang/String;)Lcom/tendcloud/tenddata/TDGAAccount$AccountType;")) {
		jstring jaccountType = t.env->NewStringUTF(TDCCAccountTypeString[accountType]);
		jobject jtype = type.env->CallStaticObjectMethod(type.classID, type.methodID, jaccountType);
		t.env->CallVoidMethod((jobject)mAccount, t.methodID, jtype);
		t.env->DeleteLocalRef(t.classID);
		t.env->DeleteLocalRef(jtype);
		t.env->DeleteLocalRef(jaccountType);
		t.env->DeleteLocalRef(type.classID);
	}
}

void TDCCAccount::setGender(TDCCGender gender) {
	TDGAJniMethodInfo t;
	TDGAJniMethodInfo type;
	if (mAccount
		&& TDGAJniHelper::getMethodInfo(t
		, JAVA_CLASS_NAME
		, "setGender"
		, "(Lcom/tendcloud/tenddata/TDGAAccount$Gender;)V")
		&& TDGAJniHelper::getStaticMethodInfo(type
		, JAVA_CLASS_GENDER
		, "valueOf"
		, "(Ljava/lang/String;)Lcom/tendcloud/tenddata/TDGAAccount$Gender;")) {

		jstring jgender = type.env->NewStringUTF(TDCCGenderString[gender]);
		jobject jtype = type.env->CallStaticObjectMethod(type.classID, type.methodID, jgender);
		type.env->DeleteLocalRef(jgender);
		t.env->CallVoidMethod((jobject)mAccount, t.methodID, jtype);
		t.env->DeleteLocalRef(t.classID);
		t.env->DeleteLocalRef(jtype);
		t.env->DeleteLocalRef(type.classID);
	}
}
