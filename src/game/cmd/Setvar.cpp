#include <bgame/impl.h>

namespace cmd {

///////////////////////////////////////////////////////////////////////////////

Setvar::Setvar()
    : AbstractBuiltin( "setvar" )
{
    __usage << xvalue( "!" + _name ) << " [" << xvalue( "fastpanzer" ) << ']' << " [0 - 45]\n" << "Sets death count for custom fast panzer calculations - the higher the faster, up to around 45";
    __descr << "Sets values for different session variables.";
}

///////////////////////////////////////////////////////////////////////////////

Setvar::~Setvar()
{
}

///////////////////////////////////////////////////////////////////////////////

AbstractCommand::PostAction
Setvar::doExecute( Context& txt )
{
    if (txt._args.size() > 3)
        return PA_USAGE;

    Buffer buf;

    // If there are no arguments, just report usage
    if (txt._args.size() == 1) {
        return PA_USAGE;
    }
        
    string vartoset = txt._args[1];
    str::toLower(vartoset);
    

    if (vartoset == "fastpanzer") {
		// Can't use string here because ubuntu compiler isn't version 11 so doesn't
		// support stoi() method (string to int).  Have to use older atoi() which requires
		// const char*
		const char *deathstoset = txt._args[2].c_str();
		int iDeathsToSet = atoi(deathstoset);
		if (iDeathsToSet >= 0 && iDeathsToSet <= 10000)
		{
			txt._client->gclient.sess.deathsforpanzerreload = iDeathsToSet;
			// Notify user changes have been made
			buf << _name << ": fastpanzer count has been set to " << xvalue( iDeathsToSet ) << '.';
			printCpm( txt._client, buf, true );
		}
		else {
			txt._ebuf << "Invalid fastpanzer count (should be between 0 and 10000, though realistically only uses value as high as 45): " << xvalue( txt._args[2] );
			return PA_ERROR;
		}
    }
	else if (vartoset == "panzerrecoil") {
		if (txt._args[2] == "on" || txt._args[2] == "off")
		{
			bool bPanzerRecoil = (bool)(txt._args[2] == "on");
			txt._client->gclient.sess.panzerrecoil = bPanzerRecoil;
			// Notify user changes have been made
			buf << _name << ": panzerrecoil has been turned " << xvalue( txt._args[2] ) << '.';
			printCpm( txt._client, buf, true );
		}
		else {
			txt._ebuf << "Invalid panzerrecoil value (should be 'on' or 'off'): " << xvalue( txt._args[2] );
			return PA_ERROR;
		}
	}
    else {
        txt._ebuf << "Invalid argument: " << xvalue( txt._args[1] );
        return PA_ERROR;
    }

    return PA_NONE;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace cmd
