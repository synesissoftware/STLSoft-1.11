# STLSoft - Known Issues:


> **Semi-frozen / maintenance**
>
> **STLSoft-1.11** is a versioned, maintenance-oriented line. It remains available for
> consumers that must stay on the 1.11 API (for example compatibility matrices),
> but all **new development** and **new consumers** MUST use
> **[synesissoftware/STLSoft](https://github.com/synesissoftware/STLSoft)** (tip).
> Feature work belongs on tip; this repository only receives recognition,
> packaging, and smoke/CI fixes required by historical consumers.

----


## Maintenance policy

* Feature work and new consumers belong on **[synesissoftware/STLSoft](https://github.com/synesissoftware/STLSoft)** (tip).
* This 1.11 line is **semi-frozen**: recognition, packaging, smoke, and CI fixes for historical consumers only.


## STLSoft 1.11 Known Issues:

* The documentation is still lacking. This will be addressed in the release of 1.11.

* Several `unixstl::system_traits` methods are declared but not defined, with the intention to flesh them out from Linux system calls (and have emulations/workarounds for other architectures). We're keen to see pull-requests on this.


<!-- ########################### end of file ########################### -->

