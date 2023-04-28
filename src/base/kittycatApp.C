#include "kittycatApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
kittycatApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

kittycatApp::kittycatApp(InputParameters parameters) : MooseApp(parameters)
{
  kittycatApp::registerAll(_factory, _action_factory, _syntax);
}

kittycatApp::~kittycatApp() {}

void
kittycatApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"kittycatApp"});
  Registry::registerActionsTo(af, {"kittycatApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
kittycatApp::registerApps()
{
  registerApp(kittycatApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
kittycatApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  kittycatApp::registerAll(f, af, s);
}
extern "C" void
kittycatApp__registerApps()
{
  kittycatApp::registerApps();
}
