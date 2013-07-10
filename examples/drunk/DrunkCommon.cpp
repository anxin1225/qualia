#include "DrunkCommon.h"

void runDrunk() {
  DrunkAgent agent; // the agent
  DrunkEnvironment environment; // the environment

  // Qualia is constructed using an agent and an environment
  Qualia qualia(&agent, &environment);

  qualia.init();
  qualia.start();
  for (int i=0; i<100; i++)
    qualia.step();
}
