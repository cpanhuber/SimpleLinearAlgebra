cc_library(
    name = "array_algebra",
    hdrs = glob(
        [
            "include/ned_ecef/algebra/*.h",
            "include/ned_ecef/algebra/detail/*.h",
        ],
    ),
    strip_include_prefix = "include/",
)

cc_library(
    name = "ned_ecef_lib",
    hdrs = glob(["include/ned_ecef/*.h"]),
    strip_include_prefix = "include/",
    deps = [
        ":array_algebra",
    ],
)

cc_test(
    name = "array_algebra_spec",
    srcs = ["test/array_algebra_spec.cpp"],
    deps = [
        "@gtest//:gtest_main",
        ":array_algebra",
    ],
)

cc_test(
    name = "ned_ecef_spec",
    srcs = ["test/ned_ecef_spec.cpp"],
    deps = [
        "@gtest//:gtest_main",
        ":ned_ecef_lib",
    ],
)
