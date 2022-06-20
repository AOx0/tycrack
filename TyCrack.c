#include <objc/runtime.h>
#include <stdio.h>

bool override_hasLicense() { return true; }

void override_showTrailEnd() { return; }

long long override_dayRemains() { return 365; }

void override_onUnfillLicense() { return; }

void *override_jsWhenUnfillLicense() { return NULL; }

__attribute__((constructor)) static void init() {
  Class LicenseManager = objc_getClass("LicenseManager");

  SEL hasLicense = sel_registerName("hasLicense");
  SEL dayRemains = sel_registerName("dayRemains");
  SEL showTrailEnd = sel_registerName("showTrailEnd");

  const char *hasLicenseT = method_getTypeEncoding(
      class_getInstanceMethod(LicenseManager, hasLicense));

  const char *showTrailEndT = method_getTypeEncoding(
      class_getInstanceMethod(LicenseManager, showTrailEnd));

  const char *dayRemainsT = method_getTypeEncoding(
      class_getInstanceMethod(LicenseManager, dayRemains));

  class_replaceMethod(LicenseManager, hasLicense, (IMP)&override_hasLicense,
                      hasLicenseT);

  class_replaceMethod(LicenseManager, showTrailEnd, (IMP)&override_showTrailEnd,
                      showTrailEndT);

  class_replaceMethod(LicenseManager, dayRemains, (IMP)&override_dayRemains,
                      dayRemainsT);

  Class TyWindowController = objc_getClass("TyWindowController");

  SEL onUnfillLicense = sel_registerName("onUnfillLicense");
  SEL jsWhenUnfillLicense = sel_registerName("jsWhenUnfillLicense");

  const char *onUnfillLicenseT = method_getTypeEncoding(
      class_getInstanceMethod(TyWindowController, onUnfillLicense));

  const char *jsWhenUnfillLicenseT = method_getTypeEncoding(
      class_getInstanceMethod(TyWindowController, jsWhenUnfillLicense));

  class_replaceMethod(TyWindowController, onUnfillLicense,
                      (IMP)&override_onUnfillLicense, onUnfillLicenseT);

  class_replaceMethod(TyWindowController, jsWhenUnfillLicense,
                      (IMP)&override_jsWhenUnfillLicense, jsWhenUnfillLicenseT);

  puts("Loaded...");
}