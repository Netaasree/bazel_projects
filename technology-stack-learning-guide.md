# Technology Stack & Learning Guide

A structured learning path for engineers joining the Gulfstream-cpp, Longbow, or Homescreen SQL Runner projects. Covers everything from C++ fundamentals to project-specific frameworks.

---

## Phase 1: Language Foundations (C++23)

If you're new to C++, start here. If you already know C++, skip to Phase 2.

### Core C++ (2-4 weeks)

| Topic | Resources | Why |
|-------|-----------|-----|
| Memory model (RAII, move semantics, smart pointers) | *A Tour of C++* (Stroustrup), cppreference.com | All three projects are C++ — memory safety is critical |
| Templates & generic programming | cppreference, *C++ Templates: The Complete Guide* | We use concepts and template metaprogramming extensively |
| STL containers & algorithms | cppreference | Foundation before learning Folly replacements |
| Build systems basics | Bazel docs (bazel.build) | We use Bazel exclusively |

### Modern C++ (C++20/23) (1-2 weeks)

| Topic | Resources | Why |
|-------|-----------|-----|
| Concepts & constraints | cppreference `<concepts>` | We use concepts instead of virtual dispatch on hot paths |
| `std::expected<T,E>` | cppreference | Our error handling on hot paths (no exceptions) |
| Structured bindings, ranges | cppreference | Used throughout all codebases |
| Coroutines (`co_await`, `co_return`) | Lewis Baker's blog series | Folly coroutines build on this |
| `std::format`, `std::print` | cppreference | Modern string formatting |

---

## Phase 2: Folly Library (1-2 weeks)

Folly is Facebook's foundational C++ library. We use it **instead of STL** for most containers and concurrency. This is non-negotiable — PRs using `std::unordered_map` where `F14FastMap` applies will be rejected.

### Key Folly Components

| Component | Replaces | Learn |
|-----------|----------|-------|
| `folly::F14FastMap` / `F14FastSet` | `std::unordered_map/set` | Faster, more cache-friendly |
| `folly::fbstring` | `std::string` (for class members) | Small-string optimization, reference counting |
| `folly::Synchronized<T>` | `std::mutex` + manual locking | Compile-time lock safety |
| `folly::Expected<T,E>` | exceptions on hot paths | Monadic error handling |
| `folly::coro::Task<T>` | raw threads, `std::async` | Structured concurrency |
| `folly::IOBuf` | manual buffer management | Zero-copy buffer chains |
| `XLOG(INFO)` / `XLOGF` | `std::cout`, `spdlog` | Structured logging |
| `folly::futures` | `std::future` | Composable async |

### Resources
- Folly GitHub: github.com/facebook/folly
- Folly docs: `folly/docs/` in the repo
- Read the headers — Folly is well-documented in source

---

## Phase 3: Build System — Bazel (1 week)

All projects use Bazel 9 with bzlmod for dependency management.

### What to Learn

| Topic | Why |
|-------|-----|
| `BUILD.bazel` files (cc_library, cc_binary, cc_test) | Every target is defined here |
| bzlmod (`MODULE.bazel`) | External dependency management |
| `select()` for cross-platform | We target Linux (prod) and macOS (dev) |
| Query language (`bazel query`, `bazel cquery`) | Finding dependencies, reverse deps |
| Remote caching | Speeds up CI and local builds |

### Key Commands
```bash
bazel build //project:target       # Build a target
bazel test //project:tests         # Run tests
bazel run //project:binary         # Build and run
bazel query 'deps(//project:target)'  # Show dependencies
```

---

## Phase 4: Data & Messaging Technologies

| Technology | What to Learn | Resources |
|------------|---------------|-----------|
| **Apache Kafka** | Consumer groups, partitions, offsets, exactly-once semantics | kafka.apache.org/documentation |
| **librdkafka** | C/C++ Kafka client API | github.com/confluentinc/librdkafka |
| **Avro** | Schema definition, serialization/deserialization, schema registry | avro.apache.org |
| **Apache Arrow** | Columnar memory format, RecordBatch, arrays | arrow.apache.org |
| **Parquet** | Columnar file format, row groups, predicate pushdown | parquet.apache.org |
| **DuckDB** | Embedded analytical SQL engine, C++ API, window functions, CTEs | duckdb.org/docs |
| **Google Cloud Storage (GCS)** | Object storage API, gsutil, fake-GCS for testing | cloud.google.com/storage/docs |
| **FlatBuffers** | Zero-copy serialization, schema definition | google.github.io/flatbuffers |
| **HOCON** | Configuration format (superset of JSON) | github.com/lightbend/config |
| **Prometheus** | Metrics exposition format, counter/gauge/histogram | prometheus.io/docs |
| **Docker Compose** | Multi-container local testing | docs.docker.com |
| **PySpark** | DataFrame API, SQL mode (for A/B validation) | spark.apache.org/docs |
| **HiveQL → DuckDB** | Syntax differences, type coercion | Internal docs |
| **MapReduce paradigm** | Map, shuffle, reduce phases | Original Google paper |

---

## Phase 5: Testing & Validation

| Tool | Used For | Learn |
|------|----------|-------|
| **GoogleTest** | Unit tests (all projects) | github.com/google/googletest |
| **Google Benchmark** | Microbenchmarks | github.com/google/benchmark |
| **PySpark** | A/B output validation (SQL Runner vs Spark baseline) | spark.apache.org |
| **Docker Compose** | Integration tests (Kafka pipelines) | docs.docker.com |
| **sanitizers (ASan, TSan, UBSan)** | Memory safety, data races, undefined behavior | clang.llvm.org/docs |

---

## Phase 6: Observability & Operations

| Tool | Purpose |
|------|---------|
| **Prometheus** | Metrics collection and alerting |
| **Grafana** | Dashboards and visualization |
| **XLOG (Folly)** | Structured logging in all C++ projects |
| **perf / callgrind** | CPU profiling |
| **heaptrack / massif** | Memory profiling |

---

## Recommended Learning Order

1. C++23 fundamentals → 2. Folly → 3. Bazel → 4. DuckDB + Arrow/Parquet → 5. Kafka + Avro → 6. GCS + Docker Compose

---

## Quick Reference: What NOT to Use

| Don't Use | Use Instead | Reason |
|-----------|-------------|--------|
| `std::unordered_map` | `folly::F14FastMap` | Performance (cache-friendly) |
| `std::string` (members) | `folly::fbstring` | SSO + COW |
| `std::mutex` | `folly::Synchronized` | Compile-time safety |
| `std::cout` / `spdlog` | `XLOG(INFO)` | Consistent logging |
| `std::future` | `folly::coro::Task` | Structured concurrency |
| `virtual` dispatch (hot path) | Concepts + templates | Zero overhead |
| Exceptions (hot path) | `std::expected<T,E>` | No unwinding cost |
| CMake | Bazel | Project standard |
| `std::thread` | Folly executors + coroutines | Structured lifetime |
