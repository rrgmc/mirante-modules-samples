# The extension point "body" has DefaultCardBody.cpp as its default. An app that
# names a folder for "body" in its manifest gets that folder's sources instead.
mirante_add_module(rrgmcextension
    API        0.1
    SOURCES    ExtensionModule.cpp CardBody.h
    EXTENSIONS body=DefaultCardBody.cpp
    RESOURCES  icons/card.svg
    TESTS      tests/tst_body.cpp tests/tst_register.cpp tests/tst_translations.cpp)
