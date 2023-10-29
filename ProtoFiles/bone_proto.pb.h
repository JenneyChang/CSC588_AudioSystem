// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: bone_proto.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_bone_5fproto_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_bone_5fproto_2eproto

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
#include "vec3_proto.pb.h"
#include "vec4_proto.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_bone_5fproto_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_bone_5fproto_2eproto {
  static const uint32_t offsets[];
};
class bone_proto_mssg;
struct bone_proto_mssgDefaultTypeInternal;
extern bone_proto_mssgDefaultTypeInternal _bone_proto_mssg_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::bone_proto_mssg* Arena::CreateMaybeMessage<::bone_proto_mssg>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class bone_proto_mssg final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:bone_proto_mssg) */ {
 public:
  inline bone_proto_mssg() : bone_proto_mssg(nullptr) {}
  ~bone_proto_mssg() override;
  explicit PROTOBUF_CONSTEXPR bone_proto_mssg(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  bone_proto_mssg(const bone_proto_mssg& from);
  bone_proto_mssg(bone_proto_mssg&& from) noexcept
    : bone_proto_mssg() {
    *this = ::std::move(from);
  }

  inline bone_proto_mssg& operator=(const bone_proto_mssg& from) {
    CopyFrom(from);
    return *this;
  }
  inline bone_proto_mssg& operator=(bone_proto_mssg&& from) noexcept {
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

  static const bone_proto_mssg& default_instance() {
    return *internal_default_instance();
  }
  static inline const bone_proto_mssg* internal_default_instance() {
    return reinterpret_cast<const bone_proto_mssg*>(
               &_bone_proto_mssg_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(bone_proto_mssg& a, bone_proto_mssg& b) {
    a.Swap(&b);
  }
  inline void Swap(bone_proto_mssg* other) {
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
  void UnsafeArenaSwap(bone_proto_mssg* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  bone_proto_mssg* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<bone_proto_mssg>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)  final;
  void CopyFrom(const bone_proto_mssg& from);
  void MergeFrom(const bone_proto_mssg& from);
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
  void InternalSwap(bone_proto_mssg* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "bone_proto_mssg";
  }
  protected:
  explicit bone_proto_mssg(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kScaleFieldNumber = 1,
    kTransFieldNumber = 2,
    kRotFieldNumber = 3,
  };
  // .vec3_proto_mssg scale = 1;
  bool has_scale() const;
  private:
  bool _internal_has_scale() const;
  public:
  void clear_scale();
  const ::vec3_proto_mssg& scale() const;
  PROTOBUF_NODISCARD ::vec3_proto_mssg* release_scale();
  ::vec3_proto_mssg* mutable_scale();
  void set_allocated_scale(::vec3_proto_mssg* scale);
  private:
  const ::vec3_proto_mssg& _internal_scale() const;
  ::vec3_proto_mssg* _internal_mutable_scale();
  public:
  void unsafe_arena_set_allocated_scale(
      ::vec3_proto_mssg* scale);
  ::vec3_proto_mssg* unsafe_arena_release_scale();

  // .vec3_proto_mssg trans = 2;
  bool has_trans() const;
  private:
  bool _internal_has_trans() const;
  public:
  void clear_trans();
  const ::vec3_proto_mssg& trans() const;
  PROTOBUF_NODISCARD ::vec3_proto_mssg* release_trans();
  ::vec3_proto_mssg* mutable_trans();
  void set_allocated_trans(::vec3_proto_mssg* trans);
  private:
  const ::vec3_proto_mssg& _internal_trans() const;
  ::vec3_proto_mssg* _internal_mutable_trans();
  public:
  void unsafe_arena_set_allocated_trans(
      ::vec3_proto_mssg* trans);
  ::vec3_proto_mssg* unsafe_arena_release_trans();

  // .vec4_proto_mssg rot = 3;
  bool has_rot() const;
  private:
  bool _internal_has_rot() const;
  public:
  void clear_rot();
  const ::vec4_proto_mssg& rot() const;
  PROTOBUF_NODISCARD ::vec4_proto_mssg* release_rot();
  ::vec4_proto_mssg* mutable_rot();
  void set_allocated_rot(::vec4_proto_mssg* rot);
  private:
  const ::vec4_proto_mssg& _internal_rot() const;
  ::vec4_proto_mssg* _internal_mutable_rot();
  public:
  void unsafe_arena_set_allocated_rot(
      ::vec4_proto_mssg* rot);
  ::vec4_proto_mssg* unsafe_arena_release_rot();

  // @@protoc_insertion_point(class_scope:bone_proto_mssg)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::vec3_proto_mssg* scale_;
    ::vec3_proto_mssg* trans_;
    ::vec4_proto_mssg* rot_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_bone_5fproto_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// bone_proto_mssg

// .vec3_proto_mssg scale = 1;
inline bool bone_proto_mssg::_internal_has_scale() const {
  return this != internal_default_instance() && _impl_.scale_ != nullptr;
}
inline bool bone_proto_mssg::has_scale() const {
  return _internal_has_scale();
}
inline const ::vec3_proto_mssg& bone_proto_mssg::_internal_scale() const {
  const ::vec3_proto_mssg* p = _impl_.scale_;
  return p != nullptr ? *p : reinterpret_cast<const ::vec3_proto_mssg&>(
      ::_vec3_proto_mssg_default_instance_);
}
inline const ::vec3_proto_mssg& bone_proto_mssg::scale() const {
  // @@protoc_insertion_point(field_get:bone_proto_mssg.scale)
  return _internal_scale();
}
inline void bone_proto_mssg::unsafe_arena_set_allocated_scale(
    ::vec3_proto_mssg* scale) {
  if (GetArenaForAllocation() == nullptr) {
    delete static_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.scale_);
  }
  _impl_.scale_ = scale;
  if (scale) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:bone_proto_mssg.scale)
}
inline ::vec3_proto_mssg* bone_proto_mssg::release_scale() {
  
  ::vec3_proto_mssg* temp = _impl_.scale_;
  _impl_.scale_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::vec3_proto_mssg* bone_proto_mssg::unsafe_arena_release_scale() {
  // @@protoc_insertion_point(field_release:bone_proto_mssg.scale)
  
  ::vec3_proto_mssg* temp = _impl_.scale_;
  _impl_.scale_ = nullptr;
  return temp;
}
inline ::vec3_proto_mssg* bone_proto_mssg::_internal_mutable_scale() {
  
  if (_impl_.scale_ == nullptr) {
    auto* p = CreateMaybeMessage<::vec3_proto_mssg>(GetArenaForAllocation());
    _impl_.scale_ = p;
  }
  return _impl_.scale_;
}
inline ::vec3_proto_mssg* bone_proto_mssg::mutable_scale() {
  ::vec3_proto_mssg* _msg = _internal_mutable_scale();
  // @@protoc_insertion_point(field_mutable:bone_proto_mssg.scale)
  return _msg;
}
inline void bone_proto_mssg::set_allocated_scale(::vec3_proto_mssg* scale) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete static_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.scale_);
  }
  if (scale) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                static_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(scale));
    if (message_arena != submessage_arena) {
      scale = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, scale, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.scale_ = scale;
  // @@protoc_insertion_point(field_set_allocated:bone_proto_mssg.scale)
}

// .vec3_proto_mssg trans = 2;
inline bool bone_proto_mssg::_internal_has_trans() const {
  return this != internal_default_instance() && _impl_.trans_ != nullptr;
}
inline bool bone_proto_mssg::has_trans() const {
  return _internal_has_trans();
}
inline const ::vec3_proto_mssg& bone_proto_mssg::_internal_trans() const {
  const ::vec3_proto_mssg* p = _impl_.trans_;
  return p != nullptr ? *p : reinterpret_cast<const ::vec3_proto_mssg&>(
      ::_vec3_proto_mssg_default_instance_);
}
inline const ::vec3_proto_mssg& bone_proto_mssg::trans() const {
  // @@protoc_insertion_point(field_get:bone_proto_mssg.trans)
  return _internal_trans();
}
inline void bone_proto_mssg::unsafe_arena_set_allocated_trans(
    ::vec3_proto_mssg* trans) {
  if (GetArenaForAllocation() == nullptr) {
    delete static_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.trans_);
  }
  _impl_.trans_ = trans;
  if (trans) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:bone_proto_mssg.trans)
}
inline ::vec3_proto_mssg* bone_proto_mssg::release_trans() {
  
  ::vec3_proto_mssg* temp = _impl_.trans_;
  _impl_.trans_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::vec3_proto_mssg* bone_proto_mssg::unsafe_arena_release_trans() {
  // @@protoc_insertion_point(field_release:bone_proto_mssg.trans)
  
  ::vec3_proto_mssg* temp = _impl_.trans_;
  _impl_.trans_ = nullptr;
  return temp;
}
inline ::vec3_proto_mssg* bone_proto_mssg::_internal_mutable_trans() {
  
  if (_impl_.trans_ == nullptr) {
    auto* p = CreateMaybeMessage<::vec3_proto_mssg>(GetArenaForAllocation());
    _impl_.trans_ = p;
  }
  return _impl_.trans_;
}
inline ::vec3_proto_mssg* bone_proto_mssg::mutable_trans() {
  ::vec3_proto_mssg* _msg = _internal_mutable_trans();
  // @@protoc_insertion_point(field_mutable:bone_proto_mssg.trans)
  return _msg;
}
inline void bone_proto_mssg::set_allocated_trans(::vec3_proto_mssg* trans) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete static_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.trans_);
  }
  if (trans) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                static_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(trans));
    if (message_arena != submessage_arena) {
      trans = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, trans, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.trans_ = trans;
  // @@protoc_insertion_point(field_set_allocated:bone_proto_mssg.trans)
}

// .vec4_proto_mssg rot = 3;
inline bool bone_proto_mssg::_internal_has_rot() const {
  return this != internal_default_instance() && _impl_.rot_ != nullptr;
}
inline bool bone_proto_mssg::has_rot() const {
  return _internal_has_rot();
}
inline const ::vec4_proto_mssg& bone_proto_mssg::_internal_rot() const {
  const ::vec4_proto_mssg* p = _impl_.rot_;
  return p != nullptr ? *p : reinterpret_cast<const ::vec4_proto_mssg&>(
      ::_vec4_proto_mssg_default_instance_);
}
inline const ::vec4_proto_mssg& bone_proto_mssg::rot() const {
  // @@protoc_insertion_point(field_get:bone_proto_mssg.rot)
  return _internal_rot();
}
inline void bone_proto_mssg::unsafe_arena_set_allocated_rot(
    ::vec4_proto_mssg* rot) {
  if (GetArenaForAllocation() == nullptr) {
    delete static_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.rot_);
  }
  _impl_.rot_ = rot;
  if (rot) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:bone_proto_mssg.rot)
}
inline ::vec4_proto_mssg* bone_proto_mssg::release_rot() {
  
  ::vec4_proto_mssg* temp = _impl_.rot_;
  _impl_.rot_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::vec4_proto_mssg* bone_proto_mssg::unsafe_arena_release_rot() {
  // @@protoc_insertion_point(field_release:bone_proto_mssg.rot)
  
  ::vec4_proto_mssg* temp = _impl_.rot_;
  _impl_.rot_ = nullptr;
  return temp;
}
inline ::vec4_proto_mssg* bone_proto_mssg::_internal_mutable_rot() {
  
  if (_impl_.rot_ == nullptr) {
    auto* p = CreateMaybeMessage<::vec4_proto_mssg>(GetArenaForAllocation());
    _impl_.rot_ = p;
  }
  return _impl_.rot_;
}
inline ::vec4_proto_mssg* bone_proto_mssg::mutable_rot() {
  ::vec4_proto_mssg* _msg = _internal_mutable_rot();
  // @@protoc_insertion_point(field_mutable:bone_proto_mssg.rot)
  return _msg;
}
inline void bone_proto_mssg::set_allocated_rot(::vec4_proto_mssg* rot) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete static_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.rot_);
  }
  if (rot) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                static_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(rot));
    if (message_arena != submessage_arena) {
      rot = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, rot, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.rot_ = rot;
  // @@protoc_insertion_point(field_set_allocated:bone_proto_mssg.rot)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_bone_5fproto_2eproto
