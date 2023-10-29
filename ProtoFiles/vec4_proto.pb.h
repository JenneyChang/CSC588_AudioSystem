// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: vec4_proto.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_vec4_5fproto_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_vec4_5fproto_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021005 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_vec4_5fproto_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_vec4_5fproto_2eproto {
  static const uint32_t offsets[];
};
class vec4_proto_mssg;
struct vec4_proto_mssgDefaultTypeInternal;
extern vec4_proto_mssgDefaultTypeInternal _vec4_proto_mssg_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::vec4_proto_mssg* Arena::CreateMaybeMessage<::vec4_proto_mssg>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class vec4_proto_mssg final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:vec4_proto_mssg) */ {
 public:
  inline vec4_proto_mssg() : vec4_proto_mssg(nullptr) {}
  ~vec4_proto_mssg() override;
  explicit PROTOBUF_CONSTEXPR vec4_proto_mssg(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  vec4_proto_mssg(const vec4_proto_mssg& from);
  vec4_proto_mssg(vec4_proto_mssg&& from) noexcept
    : vec4_proto_mssg() {
    *this = ::std::move(from);
  }

  inline vec4_proto_mssg& operator=(const vec4_proto_mssg& from) {
    CopyFrom(from);
    return *this;
  }
  inline vec4_proto_mssg& operator=(vec4_proto_mssg&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const vec4_proto_mssg& default_instance() {
    return *internal_default_instance();
  }
  static inline const vec4_proto_mssg* internal_default_instance() {
    return reinterpret_cast<const vec4_proto_mssg*>(
               &_vec4_proto_mssg_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(vec4_proto_mssg& a, vec4_proto_mssg& b) {
    a.Swap(&b);
  }
  inline void Swap(vec4_proto_mssg* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(vec4_proto_mssg* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  vec4_proto_mssg* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<vec4_proto_mssg>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)  final;
  void CopyFrom(const vec4_proto_mssg& from);
  void MergeFrom(const vec4_proto_mssg& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(vec4_proto_mssg* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "vec4_proto_mssg";
  }
  protected:
  explicit vec4_proto_mssg(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kXFieldNumber = 1,
    kYFieldNumber = 2,
    kZFieldNumber = 3,
    kWFieldNumber = 4,
  };
  // float x = 1;
  void clear_x();
  float x() const;
  void set_x(float value);
  private:
  float _internal_x() const;
  void _internal_set_x(float value);
  public:

  // float y = 2;
  void clear_y();
  float y() const;
  void set_y(float value);
  private:
  float _internal_y() const;
  void _internal_set_y(float value);
  public:

  // float z = 3;
  void clear_z();
  float z() const;
  void set_z(float value);
  private:
  float _internal_z() const;
  void _internal_set_z(float value);
  public:

  // float w = 4;
  void clear_w();
  float w() const;
  void set_w(float value);
  private:
  float _internal_w() const;
  void _internal_set_w(float value);
  public:

  // @@protoc_insertion_point(class_scope:vec4_proto_mssg)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    float x_;
    float y_;
    float z_;
    float w_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_vec4_5fproto_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// vec4_proto_mssg

// float x = 1;
inline void vec4_proto_mssg::clear_x() {
  _impl_.x_ = 0;
}
inline float vec4_proto_mssg::_internal_x() const {
  return _impl_.x_;
}
inline float vec4_proto_mssg::x() const {
  // @@protoc_insertion_point(field_get:vec4_proto_mssg.x)
  return _internal_x();
}
inline void vec4_proto_mssg::_internal_set_x(float value) {
  
  _impl_.x_ = value;
}
inline void vec4_proto_mssg::set_x(float value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:vec4_proto_mssg.x)
}

// float y = 2;
inline void vec4_proto_mssg::clear_y() {
  _impl_.y_ = 0;
}
inline float vec4_proto_mssg::_internal_y() const {
  return _impl_.y_;
}
inline float vec4_proto_mssg::y() const {
  // @@protoc_insertion_point(field_get:vec4_proto_mssg.y)
  return _internal_y();
}
inline void vec4_proto_mssg::_internal_set_y(float value) {
  
  _impl_.y_ = value;
}
inline void vec4_proto_mssg::set_y(float value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:vec4_proto_mssg.y)
}

// float z = 3;
inline void vec4_proto_mssg::clear_z() {
  _impl_.z_ = 0;
}
inline float vec4_proto_mssg::_internal_z() const {
  return _impl_.z_;
}
inline float vec4_proto_mssg::z() const {
  // @@protoc_insertion_point(field_get:vec4_proto_mssg.z)
  return _internal_z();
}
inline void vec4_proto_mssg::_internal_set_z(float value) {
  
  _impl_.z_ = value;
}
inline void vec4_proto_mssg::set_z(float value) {
  _internal_set_z(value);
  // @@protoc_insertion_point(field_set:vec4_proto_mssg.z)
}

// float w = 4;
inline void vec4_proto_mssg::clear_w() {
  _impl_.w_ = 0;
}
inline float vec4_proto_mssg::_internal_w() const {
  return _impl_.w_;
}
inline float vec4_proto_mssg::w() const {
  // @@protoc_insertion_point(field_get:vec4_proto_mssg.w)
  return _internal_w();
}
inline void vec4_proto_mssg::_internal_set_w(float value) {
  
  _impl_.w_ = value;
}
inline void vec4_proto_mssg::set_w(float value) {
  _internal_set_w(value);
  // @@protoc_insertion_point(field_set:vec4_proto_mssg.w)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_vec4_5fproto_2eproto
