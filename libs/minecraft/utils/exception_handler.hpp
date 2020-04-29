#pragma once

#include "minecraft/net.hpp"
#include "minecraft/report.hpp"
#include "polyfill/explain.hpp"

#include <memory>
#include <spdlog/spdlog.h>

namespace minecraft::utils
{
    template < class Self >
    struct exception_handler
    {
        explicit exception_handler(std::shared_ptr< Self > &&self, std::string &&context)
        : self(std::move(self))
        , context(std::move(context))
        {
        }

        void operator()(std::exception_ptr ep) const
        {
            try
            {
                if (ep)
                    std::rethrow_exception(ep);
            }
            catch (system_error &se)
            {
                auto &&ec = se.code();
                if (ec == net::error::operation_aborted)
                    return;
                spdlog::error("{}::[{}]({})", *self, context, report(ec));
            }
            catch (...)
            {
                spdlog::error("{}::[{}] - exception: {}", *self, context, polyfill::explain());
            }
        }

        std::shared_ptr< Self > self;
        std::string             context;
    };

    struct exception_handler_standalone
    {
        exception_handler_standalone(std::string &&context)
        : context(std::move(context))
        {
        }

        void operator()(std::exception_ptr ep) const
        {
            try
            {
                if (ep)
                    std::rethrow_exception(ep);
            }
            catch (system_error &se)
            {
                auto &&ec = se.code();
                if (ec == net::error::operation_aborted)
                    return;
                spdlog::error("[{}]({})", context, report(ec));
            }
            catch (...)
            {
                spdlog::error("[{}] - exception: {}", context, polyfill::explain());
            }
        }

        std::string context;
    };

    template < class Self >
    auto make_exception_handler(Self *self, std::string context)
    {
        return exception_handler< Self >(self->shared_from_this(), std::move(context));
    }

    template < class Self >
    auto make_exception_handler(std::shared_ptr<Self> self, std::string context)
    {
        return exception_handler< Self >(std::move(self), std::move(context));
    }

    auto make_exception_handler_standalone(std::string context)
    {
        return exception_handler_standalone(std::move(context));
    }

}   // namespace minecraft::utils