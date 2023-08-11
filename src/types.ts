export class MPPError {
	code: String;
	message: String;
}

//MPPAlipayPlusClient
export class MPPConfiguration {
	clientId: String;
	envType?: String;
}

export class MPPInquireQuoteParams {
	buyCurrency: String;
	sellCurrency: String;
}

export class MPPInquireQuoteResult {
	quoteId: String;
	quoteCurrencyPair: String;
	quotePrice: String;
}

export type InquireQuoteCallback = (result?: MPPInquireQuoteResult, error?: MPPError) => void;


export class MPPCommonOAuthServiceParams{
	authClientId: String;
	scopes: Array<String>;
}

export class MPPCommonOAuthServiceResult{
	authCode: String;
	authSuccessScopes?: Array<String>;
  	authErrorScopes?: Array<String>;
}


export type CommonOAuthServiceCallback = (result?: MPPCommonOAuthServiceResult, error?: MPPError) => any;

export interface ICommonOAuthService{
	getAuthCode(commonOAuthServiceParams: MPPCommonOAuthServiceParams, commonOAuthServiceCallback: CommonOAuthServiceCallback): void;
}


//MPPAlipayPlusClientMPM
export class MPPLaunchParams{
	url: String;
	userAgent?: String;
}

export class MPPLaunchResult{

}

export type LaunchCallback = (result?: MPPLaunchResult, error?: MPPError) => void;

export class MPPDecodeServiceParams{
	codeValue: String;
}

export class MPPDecodeServiceResult{

}

export type DecodeServiceCallback = (result?: MPPDecodeServiceResult, error?: MPPError) => any;

export interface IMPMService{
	decode(decodeServiceParams: MPPDecodeServiceParams, decodeServiceCallback: DecodeServiceCallback): void;
}

//log
export class MPPLog {
	type: String;
	name: String;
	parameters: String;
}

// MPPAlipayPlusClientLogger
export interface ILoggerService{
	log(log:MPPLog): void;
}


// MPPAcceptanceMarkLogo
export class MPPAcceptanceMarkLogo {
	logoName?: String;
	logoUrl: String;
}