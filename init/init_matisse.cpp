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
    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("T530XX") == 0) {
        /* matissewifixx */
        property_override("ro.build.description", "matissewifixx-user 5.0.2 LRX22G T530XXS1BRH1 release-keys");
        set_ro_product_prop("device", "matissewifi");
        set_ro_product_prop("fingerprint", "samsung/matissewifixx/matissewifi:5.0.2/LRX22G/T530XXS1BRH1:user/release-keys");
        set_ro_product_prop("model", "SM-T530");
        set_ro_product_prop("name", "matissewifi");
        wifi_properties();
    } else if (bootloader.find("T530NU") == 0) {
        /* matissewifiue */
        property_override("ro.build.description", "matissewifiue-user 5.0.2 LRX22G T530NUUEU1BQC1 release-keys");
        set_ro_product_prop("device", "matissewifiue");
        set_ro_product_prop("fingerprint", "samsung/matissewifiue/matissewifiue:5.0.2/LRX22G/T530NUUEU1BQC1:user/release-keys");
        set_ro_product_prop("model", "SM-T530NU");
        set_ro_product_prop("name", "matissewifiue");
        wifi_properties();
    } else if (bootloader.find("T531XX") == 0) {
        /* matisse3gxx */
        property_override("ro.build.description", "matisse3gxx-user 5.0.2 LRX22G T531XXS1BRH1 release-keys");
        set_ro_product_prop("device", "matisse3g");
        set_ro_product_prop("fingerprint", "samsung/matisse3gxx/matisse3g:5.0.2/LRX22G/T531XXS1BRH1:user/release-keys");
        set_ro_product_prop("model", "SM-T531");
        set_ro_product_prop("name", "matisse3g");
        gsm_properties();
    } else if (bootloader.find("T532XX") == 0) {
        /* matisse3gjvxx */
        property_override("ro.build.description", "matisse3gjv-user 5.0.2 LRX22G T532JVS1BQB1 release-keys");
        set_ro_product_prop("device", "matisse3gjv");
        set_ro_product_prop("fingerprint", "samsung/matisse3gjv/matisse3g:5.0.2/LRX22G/T532JVS1BQB1:user/release-keys");
        set_ro_product_prop("model", "SM-T532");
        set_ro_product_prop("name", "matisse3gjv");
        gsm_properties();
    } else if (bootloader.find("T535XX") == 0) {
        /* matisseltexx */
        property_override("ro.build.description", "matisseltexx-user 5.0.2 LRX22G T535XXS1BRJ2 release-keys");
        set_ro_product_prop("device", "matisselte");
        set_ro_product_prop("fingerprint", "samsung/matisseltexx/matisselte:5.0.2/LRX22G/T535XXS1BRJ2:user/release-keys");
        set_ro_product_prop("model", "SM-T535");
        set_ro_product_prop("name", "matisselte");
        lte_properties();
    } else {
        wifi_properties();
    }
    
    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader <<  " setting build properties for "
    << device <<  " device" << std::endl;
}
