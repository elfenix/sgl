#include "mock_application.h"

#include <sgl/application.h>
#include <gtest/gtest.h>


namespace sgl_test
{
    using namespace sgl;

    struct application_run_single {
        bool has_run = false;

        static int run(void* ctx, uintptr_t d) {
            application_run_single* v = reinterpret_cast<application_run_single*>(d);
            v->has_run = true;
            return application::exit_run;
        }
    };

    struct application_run_functor {
        bool has_run = false;

        int operator()(context& ctx) {
            has_run = true;
            return application::exit_run;
        }
    };

    TEST(application, run_c)
    {
        mock_application m;

        application_run_single s;

        m.run(application_run_single::run, reinterpret_cast<uintptr_t>(&s));
        ASSERT_TRUE(s.has_run);
    }

    TEST(application, run_proxy)
    {
        mock_application m;
        bool capture = false;
        
        application_run_functor f1;
        m.run(f1);
        ASSERT_TRUE(f1.has_run);

        m.run([&capture](context& ctx) { capture = true; return application::exit_run; });
        ASSERT_TRUE(capture);
    }
}
