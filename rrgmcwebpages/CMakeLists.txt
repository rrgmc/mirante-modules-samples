# The web pages under web/ are compiled in with RESOURCES, as
# :/modules/rrgmcwebpages/web/..., which the core serves as
# module://rrgmcwebpages/....
mirante_add_module(rrgmcwebpages
    API       0.1
    SOURCES   WebPagesModule.cpp WebPages.h
    RESOURCES icons/webpages.svg
              web/index.html web/page.js web/page.css web/greetings.json
    TESTS     tests/tst_pages.cpp tests/tst_register.cpp tests/tst_translations.cpp)
