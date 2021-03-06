#include <bgame/impl.h>

namespace cmd {

///////////////////////////////////////////////////////////////////////////////

Shuffle::Shuffle()
    : AbstractBuiltin( "shuffle" )
{
    __usage << xvalue( "!" + _name );
    __descr << "Shuffles the teams based on the rate of XP gain.";
}

///////////////////////////////////////////////////////////////////////////////

Shuffle::~Shuffle()
{
}

///////////////////////////////////////////////////////////////////////////////

AbstractCommand::PostAction
Shuffle::doExecute( Context& txt )
{
    if (txt._args.size() != 1)
        return PA_USAGE;

    G_shuffleTeams();
    return PA_NONE;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace cmd
