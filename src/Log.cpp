#include "Log.h"
#include "Logger.h"
#include "ApplianceBase.h"

namespace dudanov {

LoggerFn logger_;
void setLogger(LoggerFn logger) { logger_ = logger; }

void sv_log_printf_(int level, const char *tag, int line, const char *format, ...) {
  if (logger_ == nullptr)
    return;
  va_list arg;
  va_start(arg, format);
  logger_(level, tag, line, format, arg);
  va_end(arg);
}

void sv_log_printf_(int level, const char *tag, int line, const __FlashStringHelper *format, ...) {
  if (logger_ == nullptr)
    return;
  va_list arg;
  va_start(arg, format);
  logger_(level, tag, line, format, arg);
  va_end(arg);
}

}  // namespace dudanov
