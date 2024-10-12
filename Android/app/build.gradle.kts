plugins {
    alias(libs.plugins.android.application)
    alias(libs.plugins.kotlin.android)
}

android {
    namespace = "com.glordim.pong"
    compileSdk = 34
    ndkVersion = "27.1.12297006"

    defaultConfig {
        applicationId = "com.glordim.pong"
        minSdk = 33
        targetSdk = 34
        versionCode = 1
        versionName = "1.0"
        externalNativeBuild {
            cmake {
                cppFlags += "-std=c++20"
            }
        }
        ndk {
            //abiFilters += listOf("armeabi-v7a", "arm64-v8a", "x86", "x86_64")
            abiFilters += listOf("x86_64")
        }
    }

    buildTypes {
        release {
            isMinifyEnabled = false
            proguardFiles(
                getDefaultProguardFile("proguard-android-optimize.txt"),
                "proguard-rules.pro"
            )
        }
    }
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_1_8
        targetCompatibility = JavaVersion.VERSION_1_8
    }
    kotlinOptions {
        jvmTarget = "1.8"
    }
    buildFeatures {
        prefab = true
    }
    externalNativeBuild {
        cmake {
            path = file("../../CMakeLists.txt")
            version = "3.22.1"
        }
    }
    //sourceSets["main"].jniLibs.srcDirs("E:/HodEngine/build_android_x64/Release")
}

dependencies {

    implementation(libs.androidx.core.ktx)
    implementation(libs.androidx.appcompat)
    implementation(libs.material)
    implementation(fileTree("E:/HodEngine/Externals/agdk-libraries-2023.3.0.0/jar-classes/game-activity") { include("*.jar") })
    //implementation(fileTree("E:/HodEngine/Externals/agdk-libraries-2023.3.0.0/jar-classes/game-text-input") { include("*.jar") })
    //implementation(libs.androidx.games.activity)
}