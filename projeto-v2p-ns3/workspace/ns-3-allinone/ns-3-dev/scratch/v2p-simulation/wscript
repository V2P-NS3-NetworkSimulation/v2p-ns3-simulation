import os

def options(opt):
    opt.load("compiler_cxx")

def configure(conf):
    conf.env.append_value("CXXFLAGS", "-Wall -O3")
    conf.env.append_value("LINKFLAGS", "-Wall")

def build(bld):
    bld.program(
        target="main",
        source=["main.cc", "vehicle.cc", "pedestrian.cc"],
        use="core"
    )
