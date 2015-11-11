#pragma once    
#ifndef ___UTIL_POCOLOGUTIL_H___    
#define ___UTIL_POCOLOGUTIL_H___    
  
#include "Poco/ConsoleChannel.h"    
#include "Poco/FormattingChannel.h"    
#include "Poco/PatternFormatter.h"    
#include "Poco/Logger.h"    
#include "Poco/AutoPtr.h"    
#include "Poco/FileChannel.h"    
#include "Poco/LocalDateTime.h"  
#include "Poco/Thread.h"  

#include "../Utils/StrUtil.hpp"

using Poco::ConsoleChannel;    
using Poco::FormattingChannel;    
using Poco::PatternFormatter;    
using Poco::Logger;    
using Poco::AutoPtr;    
using Poco::FileChannel;    
using Poco::Thread;  
using Poco::LocalDateTime;  

using namespace StrUtil;
  
namespace PocoUtil {  
    namespace LogHelper {  
#pragma region Declaration  
        class EasyLog  {    
        public:    
            static EasyLog * Inst(){    
                if (0 == _instance.get()){    
                    _instance.reset(new EasyLog);    
                }    
                return _instance.get();    
            }    
    
            /* 写日志的方法（可配置ISACTIVE，设置是否回显到控制台）  
               @msg 日志信息  
             */  
            void Log(std::string msg);    
        private:    
            EasyLog(void);    
            virtual ~EasyLog(void){}    
            friend class std::auto_ptr<EasyLog>;    
            static std::auto_ptr<EasyLog> _instance;    
  
            void LogInit();  
        };    
#pragma endregion  
#pragma region Definition  
        std::auto_ptr<EasyLog> EasyLog::_instance;  
  
        EasyLog::EasyLog() {  
            LogInit();  
        }  
  
        void EasyLog::LogInit() {  
            AutoPtr<FileChannel> pChannel(new FileChannel);   

			std::string path = StrUtil::GetModulePath();			

            pChannel->setProperty("path", "test");    
            pChannel->setProperty("rotation", "never");    
            pChannel->setProperty("archive", "timestamp");    
  
            AutoPtr<PatternFormatter> pPF(new PatternFormatter);    
            pPF->setProperty("pattern", "%Y-%m-%d %H:%M:%S %s: %t");    
            pPF->setProperty("times","local");  
            AutoPtr<FormattingChannel> pFC(new FormattingChannel(pPF, pChannel));    
            Logger::root().setChannel(pFC);    
        }  
  
        void EasyLog::Log(std::string loginfo) {   
            Logger::get(" ---> ").information(loginfo);  
        }  
          
#pragma endregion   
    }  
}  
  
#endif  // end of ___UTIL_EASYLOG_H___