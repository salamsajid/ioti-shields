// eJyVUu9P4kAQzf4nxvihxNhtQaNuLiZI0JOWwl25S_1zULHSgK2237iwI_1PVuVyEGldyl6Y_0Zvtn35s1glbsKcq6FLHnO2N2inGipiE88c7XIsetSva6A3kLvRfXj82aw9gfhtNcPRuPB6NnDCK_0jML4YjLpXd_02f3b_1t_0aWbHR8qHD9iLFat8M8yCtbzRfT0Oxh1Lnub_1lUYd1bBpuPdt4ebX_03WrD7oRzwMk170YJUZlZhMZJGIsbmlPhcJrHhR5YBudmMV50KfeMQUMaZQK1HOiM35X_0SaezlCC0gFpzhNMOMKUmo4xBlmAvIUqSU8WzbplpOiqN87QEdxzGIb0JRrTkpZgmfMnIpcQ_02q5RtLmQMvjVzGbOJje4yZ_1hgzDZpHTcjYls6ikz1wBpO55XVEJZXp3Z2BTgpA5DNwGg3SXVXKRAZup_1qOelPyP1Mlgii7FcS4vEBQDynZOjeH9e77nXoX16TyMOm_1bwQpjIhP9D7Zm_06uTWvGG9ppEMVfuksoNX5f6RPHsetydHr0taHmh92xBuF2CEOueHHwRLtqxoZXQ3QXBD



#ifndef SPL_OPER_INSTANCE_SHIELD_H_
#define SPL_OPER_INSTANCE_SHIELD_H_

#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/Operator/State/StateHandler.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMS42Ky1OLfJMKTbOTq0sNs9NLS5OTE8FAHEVAk7.h"
#include "../type/BeJwrMS42Ky1OLfJMKbYsSix3LUvNKykuNjRKTC7JzM8LSCxKzC0GAPzQA3g.h"
#include <SPL_JNIFunctions_com_ibm_iot4i_examples.h>

#include <bitset>

#define MY_OPERATOR shield$OP
#define MY_BASE_OPERATOR shield_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMS42Ky1OLfJMKTbOTq0sNs9NLS5OTE8FAHEVAk7 IPort0Type;
    typedef SPL::BeJwrMS42Ky1OLfJMKbYsSix3LUvNKykuNjRKTC7JzM8LSCxKzC0GAPzQA3g OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    void punctPermitProcessRaw(Punctuation const & punct, uint32_t port);
    void punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port);
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::rstring lit$0;
    SPL::rstring lit$1;
    SPL::rstring lit$2;
    
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
    void checkpointStateVariables(NetworkByteBuffer & opstate) const;
    void restoreStateVariables(NetworkByteBuffer & opstate);
    void checkpointStateVariables(Checkpoint & ckpt);
    void resetStateVariables(Checkpoint & ckpt);
    void resetStateVariablesToInitialState();
    bool hasStateVariables() const;
    void resetToInitialStateRaw();
    void checkpointRaw(Checkpoint & ckpt);
    void resetRaw(Checkpoint & ckpt);
private:
    static bool globalInit_;
    static bool globalIniter();
    ParameterMapType paramValues_;
    ParameterMapType& getParameters() { return paramValues_;}
    void addParameterValue(std::string const & param, ConstValueHandle const& value)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create(value));
    }
    void addParameterValue(std::string const & param)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create());
    }
};


class MY_OPERATOR : public MY_BASE_OPERATOR
{
public:
   MY_OPERATOR() {}
  
   void process(Tuple const & tuple, uint32_t port);
   void process(Punctuation const & punct, uint32_t port);
   
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_SHIELD_H_

