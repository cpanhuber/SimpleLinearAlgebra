cc_library(
    name = "silia_types_lib",
    hdrs = glob(
        [
            "include/silia/types/*.h",
            "include/silia/types/detail/*.h",
        ],
    ),
    strip_include_prefix = "include/",
)

cc_library(
    name = "silia_operations_lib",
    hdrs = glob(
        [
            "include/silia/operations/*.h",
            "include/silia/operations/detail/*.h",
        ],
    ),
    strip_include_prefix = "include/",
    deps = [
        ":silia_types_lib",
    ],
)

cc_test(
    name = "types_spec",
    srcs = glob(["test/types/*.cpp"]),
    deps = [
        "@gtest//:gtest_main",
        ":silia_types_lib",
    ],
)

cc_test(
    name = "operations_spec",
    srcs = glob(["test/operations/*.cpp"]),
    deps = [
        "@gtest//:gtest_main",
        ":silia_operations_lib",
    ],
)
