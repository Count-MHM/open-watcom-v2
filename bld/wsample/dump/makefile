#pmake: cpu_386
host_cpu = 386

!include cproj.mif
!include defrule.mif
!include deftarg.mif

smpdump.exe : smpdump.c
    @%make echo_bldccl
    $(bld_ccl) -I"$(dig_dir)/h" -I"$(wsample_dir)/h" $(bld_cclflags) $[@ $(bld_ldflags)
