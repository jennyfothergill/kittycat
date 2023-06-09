//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "kittycatTestApp.h"
#include "kittycatApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
kittycatTestApp::validParams()
{
  InputParameters params = kittycatApp::validParams();
  return params;
}

kittycatTestApp::kittycatTestApp(InputParameters parameters) : MooseApp(parameters)
{
  kittycatTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

kittycatTestApp::~kittycatTestApp() {}

void
kittycatTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  kittycatApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"kittycatTestApp"});
    Registry::registerActionsTo(af, {"kittycatTestApp"});
  }
}

void
kittycatTestApp::registerApps()
{
  registerApp(kittycatApp);
  registerApp(kittycatTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
kittycatTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  kittycatTestApp::registerAll(f, af, s);
}
extern "C" void
kittycatTestApp__registerApps()
{
  kittycatTestApp::registerApps();
}
