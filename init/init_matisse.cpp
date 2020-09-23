/*
 Copyright (c) 2016, The Linux Foundation. All rights reserved.
 Copyright (c) 2017-2018, The LineageOS Project. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are
 met:
 * Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 copyright notice, this list of conditions and the following
 disclaimer in the documentation and/or other materials provided
 with the distribution.
 * Neither the name of The Linux Foundation nor the names of its
 contributors may be used to endorse or promote products derived
 from this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <android-base/logging.h>
#include <android-base/properties.h>

#include "property_service.h"

#include "init_msm8226.h"

using android::base::GetProperty;
using android::init::property_set;

void vendor_load_properties()
{
    std::string platform = GetProperty("ro.board.platform", "");
    if (platform != ANDROID_TARGET)
        return;

    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("T530XX") == 0) {
        /* matissewifixx */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/matissewifixx/matissewifi:5.0.2/LRX22G/T530XXS1BRH1:user/release-keys");
        property_override("ro.bootimage.build.fingerprint", "samsung/matissewifixx/matissewifi:5.0.2/LRX22G/T530XXS1BRH1:user/release-keys");
        property_override("ro.build.description", "matissewifixx-user 5.0.2 LRX22G T530XXS1BRH1 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-T530");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "matissewifi");
        wifi_properties("wifi-only", "1");
    } else if (bootloader.find("T530NU") == 0) {
        /* matissewifiue */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/matissewifiue/matissewifiue:5.0.2/LRX22G/T530NUUEU1BQC1:user/release-keys");
        property_override("ro.bootimage.build.fingerprint", "samsung/matissewifiue/matissewifiue:5.0.2/LRX22G/T530NUUEU1BQC1:user/release-keys");
        property_override("ro.build.description", "matissewifiue-user 5.0.2 LRX22G T530NUUEU1BQC1 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-T530NU");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "matissewifi");
        wifi_properties("wifi-only", "1");
    } else if (bootloader.find("T531XX") == 0) {
        /* matisse3gxx */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/matisse3gxx/matisse3g:5.0.2/LRX22G/T531XXS1BRH1:user/release-keys");
        property_override("ro.bootimage.build.fingerprint", "samsung/matisse3gxx/matisse3g:5.0.2/LRX22G/T531XXS1BRH1:user/release-keys");
        property_override("ro.build.description", "matisse3gxx-user 5.0.2 LRX22G T531XXS1BRH1 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-T531");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "matisse3g");
        gsm_properties("3", "0");
    } else if (bootloader.find("T532XX") == 0) {
        /* matisse3gjvxx */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/matisse3gjv/matisse3g:5.0.2/LRX22G/T532JVS1BQB1:user/release-keys");
        property_override("ro.bootimage.build.fingerprint", "samsung/matisse3gjv/matisse3g:5.0.2/LRX22G/T532JVS1BQB1:user/release-keys");
        property_override("ro.build.description", "matisse3gjv-user 5.0.2 LRX22G T532JVS1BQB1 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-T532");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "matisse3gjv");
        gsm_properties("3", "0");
    } else if (bootloader.find("T535XX") == 0) {
        /* matisseltexx */
        property_override_dual("ro.build.fingerprint", "ro.vendor.build.fingerprint", "samsung/matisseltexx/matisselte:5.0.2/LRX22G/T535XXS1BRJ2:user/release-keys");
        property_override("ro.bootimage.build.fingerprint", "samsung/matisseltexx/matisselte:5.0.2/LRX22G/T535XXS1BRJ2:user/release-keys");
        property_override("ro.build.description", "matisseltexx-user 5.0.2 LRX22G T535XXS1BRJ2 release-keys");
        property_override_dual("ro.product.model", "ro.vendor.product.model", "SM-T535");
        property_override_dual("ro.product.device", "ro.vendor.product.device", "matisselte");
        gsm_properties("9", "1");
    } else {
        wifi_properties("wifi-only", "1");
    }

    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader <<  " setting build properties for "
        << device <<  " device" << std::endl;
}
