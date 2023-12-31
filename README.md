# react-native-mppalipayplusclient

## Before you begin
Before you get started, ensure that the following requirements are met:
### React Native

- Ensure that the React Native version is greater than 0.6.0.
### iOS

- Install the following tools:
   - Xcode 12.* or later
- Ensure that the minimum deployment target is set to iOS 11.0 or later.
### Android

- Install or update Android Studio to a working version.
- Use target API level 15 (ICE_CREAM_SANDWICH_MR1) or higher.
- Use Gradle 4.1 or higher.
- Set up a physical device or use an emulator to run your app.
## Get started
### Step 1. Add SDK to your project

1. Add the react-native-mppalipayplusclient-1.0.0.tgz file to your project.
2. In the package.json file, add the file to your dependencies and install the dependency.
```javascript
  "dependencies": {
      ...
    "react-native-mppalipayplusclient": "file:{your tgz path}"
  },
```

3. For iOS, run the `pod install` command.
4. For Android, add the iaptinylog.aar, sdk-alupayplus.aar, and sdk-mpm.aar dependencies  provided by the SDK into your project in the native part and sync the dependencies.
```javascript
─ libs
   ├── iaptinylog.aar
   ├── sdk-alipayplus.aar
   └── sdk-mpm.aar
- src
- build.gradle
```
```javascript
implementation fileTree(dir: "libs", include: ["*.jar", "*.aar"])
```

### Step 2. Set up the SDK
Initialize the SDK by calling the **setConfiguration** API:
```javascript
import {MPPAlipayPlusClient,MPPConfiguration} from 'react-native-mppalipayplusclient';

var configuraiton = new MPPConfiguration();
configuraiton.clientId = yourClientId;
MPPAlipayPlusClient.setConfiguration(configuraiton);
```

### Step 3. Register services
Register the `IMPMService` and `ICommonOAuthService` services to use the payment capability of the SDK:
```javascript
import { DecodeServiceCallback, MPPDecodeServiceParams, MPPDecodeServiceResult, IMPMService, MPPError } from "react-native-mppalipayplusclient";

export class MPMServiceImpl implements IMPMService {
    decode(decodeServiceParams: MPPDecodeServiceParams, decodeServiceCallback: DecodeServiceCallback): void {
    if(true){
      //success situation
      var other;
            var decodeServiceResult = new MPPDecodeServiceResult();
            decodeServiceCallback(decodeServiceResult, other);
    }else{
      //fail situation
        var other;
      var error = new MPPError();
      error.code = yourErrorCode;
      error.message = yourErrorMessage;
      decodeServiceCallback(other, error);
    }
}
```
```javascript
import { CommonOAuthServiceCallback, MPPCommonOAuthServiceParams, MPPCommonOAuthServiceResult, ICommonOAuthService, MPPError } from "react-native-mppalipayplusclient";

export class MPMServiceImpl implements ICommonOAuthService {
  if(true){
    //success situation
    var commonOAuthServiceResult = new MPPCommonOAuthServiceResult();
    commonOAuthServiceResult.authCode = yourAuthCode;
    var other;
    commonOAuthServiceCallback(commonOAuthServiceResult, other);
  }else{
    var error = new MPPError();
    error.code = yourErrorCode;
    error.message = yourErrorMessage;
    commonOAuthServiceCallback(other, error);
  }
}
```
```javascript
import {MPPAlipayPlusClient,MPPAlipayPlusClientMPM} from 'react-native-mppalipayplusclient';

MPPAlipayPlusClient.registerCommonOAuthService(new CommonOAuthServiceImpl());
MPPAlipayPlusClientMPM.registerMPMDecodeService(new MPMServiceImpl());
```

## Next steps
After you have integrated the SDK, you can move on to use the SDK in the Merchant-presented Mode Payment scenario.
