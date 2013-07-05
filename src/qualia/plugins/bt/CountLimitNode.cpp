#include "BehaviorTree.h"

using namespace BehaviorTree;
using namespace std;
BEHAVIOR_STATUS CountLimitNode::execute(void* agent)
{
	if (current_rep == limit)
		return BT_FAILURE;
	if (nChildren == 0)
	{
		current_rep++;
		return BT_SUCCESS;
	}
	else
	{
		BEHAVIOR_STATUS status = children[0]->execute(agent);
		if (status == BT_SUCCESS || status == BT_FAILURE)
		{
			current_rep++; //only increment the count when we've finished a job
			initChildren(agent);
		}
		return status;
	}
}

void CountLimitNode::init( void* agent )
{
	if (allow_reinitialize)
	{
		current_rep = 0;
	}
	initChildren(agent);
}

void CountLimitNode::initChildren(void* agent)
{
	if (nChildren == 1)
		children[0]->init(agent);
}

BehaviorTreeInternalNode* CountLimitNode::addChild( BehaviorTreeNode* newChild )
{
  if (nChildren == 0)
    BehaviorTreeInternalNode::addChild(newChild);
  else
    Q_ERROR("Cannot add more than one child to a count limit node");

  return this;
}

CountLimitNode::CountLimitNode(BehaviorTreeNode* child, int _limit, bool _allow_reinitialize)
  : BehaviorTreeInternalNode( &child, 1 )
{
	limit = _limit;
	allow_reinitialize = _allow_reinitialize;
	current_rep = 0;
};
