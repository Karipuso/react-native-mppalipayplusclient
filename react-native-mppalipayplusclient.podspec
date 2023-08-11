# react-native-mppalipayplusclient.podspec

require "json"

package = JSON.parse(File.read(File.join(__dir__, "package.json")))

Pod::Spec.new do |s|
  s.name         = "react-native-mppalipayplusclient"
  s.version      = package["version"]
  s.summary      = package["description"]
  s.description  = <<-DESC
                  react-native-mppalipayplusclient
                   DESC
  s.homepage     = "https://github.com/github_account/react-native-mppalipayplusclient"
  # brief license entry:
  s.license      = "MIT"
  # optional - use expanded license entry instead:
  # s.license    = { :type => "MIT", :file => "LICENSE" }
  s.authors      = { "Your Name" => "yourname@email.com" }
  s.platforms    = { :ios => "11.0" }
  s.source       = { :git => "https://github.com/github_account/react-native-mppalipayplusclient.git", :tag => "#{s.version}" }

  s.source_files = "ios/**/*.{h,c,cc,cpp,m,mm,swift}"
  s.requires_arc = true

  s.dependency "React"
  s.vendored_frameworks = 'ios/iOS_MPPAlipayPlusClient_1.5.0/MPPAlipayPlusClient.framework', 'ios/iOS_MPPAlipayPlusClient_1.5.0/MPPAlipayPlusClientMPM.framework', 'ios/iOS_MPPAlipayPlusClient_1.5.0/IAPMinContainer.framework', 'ios/iOS_MPPAlipayPlusClient_1.5.0/IAPTinyLogger.framework'
  s.resource = 'ios/iOS_MPPAlipayPlusClient_1.5.0/IAPMinContainer.framework/IAPMinContainer.bundle'

end

