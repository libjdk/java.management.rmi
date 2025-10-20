#include <java.management.rmi.test.h>

#include <java.management.rmi.h>
#include <java.naming.h>
#include <java.management.h>
#include <java.rmi.h>
#include <java.base.h>
#include <java.security.sasl.h>
#include <java.logging.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>

void java$management$rmi$test$PreloadClass(void* eventData) {
}

void java$management$rmi$test$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$management$rmi$test$PreloadClass(eventData);
	}
	if (eventType == JCPP_LIB_EVENT_TYPE_THREAD_START) {
		$onLibThreadStart(eventData);
	}
}

$StringArray* java$management$rmi$test$GetPackages() {
	return nullptr;
}

::java::lang::ClassEntry* java$management$rmi$test$GetClassEntry($String* name) {
	return nullptr;
}

$bytes* java$management$rmi$test$GetResource($String* name) {
	return nullptr;
}

void java$management$rmi$test::init() {
	::java$management$rmi::init();
	::java$naming::init();
	::java$management::init();
	::java$rmi::init();
	::java$base::init();
	::java$security$sasl::init();
	::java$logging::init();
	::java::lang::Library lib = {
		"java.management.rmi.test", "17.35", "",
		nullptr,
		java$management$rmi$test$LibEventAction,
		java$management$rmi$test$GetPackages,
		java$management$rmi$test$GetClassEntry,
		java$management$rmi$test$GetResource
	};
	$System::addLibrary(&lib);
	$System::init();
}