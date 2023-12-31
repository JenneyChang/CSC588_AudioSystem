// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: clip_proto.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_clip_5fproto_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_clip_5fproto_2eproto

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
#include "frame_proto.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_clip_5fproto_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_clip_5fproto_2eproto {
  static const uint32_t offsets[];
};
class clip_proto_mssg;
struct clip_proto_mssgDefaultTypeInternal;
extern clip_proto_mssgDefaultTypeInternal _clip_proto_mssg_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::clip_proto_mssg* Arena::CreateMaybeMessage<::clip_proto_mssg>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class clip_proto_mssg final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:clip_proto_mssg) */ {
 public:
  inline clip_proto_mssg() : clip_proto_mssg(nullptr) {}
  ~clip_proto_mssg() override;
  explicit PROTOBUF_CONSTEXPR clip_proto_mssg(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  clip_proto_mssg(const clip_proto_mssg& from);
  clip_proto_mssg(clip_proto_mssg&& from) noexcept
    : clip_proto_mssg() {
    *this = ::std::move(from);
  }

  inline clip_proto_mssg& operator=(const clip_proto_mssg& from) {
    CopyFrom(from);
    return *this;
  }
  inline clip_proto_mssg& operator=(clip_proto_mssg&& from) noexcept {
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

  static const clip_proto_mssg& default_instance() {
    return *internal_default_instance();
  }
  static inline const clip_proto_mssg* internal_default_instance() {
    return reinterpret_cast<const clip_proto_mssg*>(
               &_clip_proto_mssg_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(clip_proto_mssg& a, clip_proto_mssg& b) {
    a.Swap(&b);
  }
  inline void Swap(clip_proto_mssg* other) {
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
  void UnsafeArenaSwap(clip_proto_mssg* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  clip_proto_mssg* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<clip_proto_mssg>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)  final;
  void CopyFrom(const clip_proto_mssg& from);
  void MergeFrom(const clip_proto_mssg& from);
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
  void InternalSwap(clip_proto_mssg* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "clip_proto_mssg";
  }
  protected:
  explicit clip_proto_mssg(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFramesFieldNumber = 3,
    kNumframesFieldNumber = 1,
    kDurationFieldNumber = 2,
  };
  // repeated .frame_proto_mssg frames = 3;
  int frames_size() const;
  private:
  int _internal_frames_size() const;
  public:
  void clear_frames();
  ::frame_proto_mssg* mutable_frames(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::frame_proto_mssg >*
      mutable_frames();
  private:
  const ::frame_proto_mssg& _internal_frames(int index) const;
  ::frame_proto_mssg* _internal_add_frames();
  public:
  const ::frame_proto_mssg& frames(int index) const;
  ::frame_proto_mssg* add_frames();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::frame_proto_mssg >&
      frames() const;

  // uint32 numframes = 1;
  void clear_numframes();
  uint32_t numframes() const;
  void set_numframes(uint32_t value);
  private:
  uint32_t _internal_numframes() const;
  void _internal_set_numframes(uint32_t value);
  public:

  // float duration = 2;
  void clear_duration();
  float duration() const;
  void set_duration(float value);
  private:
  float _internal_duration() const;
  void _internal_set_duration(float value);
  public:

  // @@protoc_insertion_point(class_scope:clip_proto_mssg)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::frame_proto_mssg > frames_;
    uint32_t numframes_;
    float duration_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_clip_5fproto_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// clip_proto_mssg

// uint32 numframes = 1;
inline void clip_proto_mssg::clear_numframes() {
  _impl_.numframes_ = 0u;
}
inline uint32_t clip_proto_mssg::_internal_numframes() const {
  return _impl_.numframes_;
}
inline uint32_t clip_proto_mssg::numframes() const {
  // @@protoc_insertion_point(field_get:clip_proto_mssg.numframes)
  return _internal_numframes();
}
inline void clip_proto_mssg::_internal_set_numframes(uint32_t value) {
  
  _impl_.numframes_ = value;
}
inline void clip_proto_mssg::set_numframes(uint32_t value) {
  _internal_set_numframes(value);
  // @@protoc_insertion_point(field_set:clip_proto_mssg.numframes)
}

// float duration = 2;
inline void clip_proto_mssg::clear_duration() {
  _impl_.duration_ = 0;
}
inline float clip_proto_mssg::_internal_duration() const {
  return _impl_.duration_;
}
inline float clip_proto_mssg::duration() const {
  // @@protoc_insertion_point(field_get:clip_proto_mssg.duration)
  return _internal_duration();
}
inline void clip_proto_mssg::_internal_set_duration(float value) {
  
  _impl_.duration_ = value;
}
inline void clip_proto_mssg::set_duration(float value) {
  _internal_set_duration(value);
  // @@protoc_insertion_point(field_set:clip_proto_mssg.duration)
}

// repeated .frame_proto_mssg frames = 3;
inline int clip_proto_mssg::_internal_frames_size() const {
  return _impl_.frames_.size();
}
inline int clip_proto_mssg::frames_size() const {
  return _internal_frames_size();
}
inline ::frame_proto_mssg* clip_proto_mssg::mutable_frames(int index) {
  // @@protoc_insertion_point(field_mutable:clip_proto_mssg.frames)
  return _impl_.frames_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::frame_proto_mssg >*
clip_proto_mssg::mutable_frames() {
  // @@protoc_insertion_point(field_mutable_list:clip_proto_mssg.frames)
  return &_impl_.frames_;
}
inline const ::frame_proto_mssg& clip_proto_mssg::_internal_frames(int index) const {
  return _impl_.frames_.Get(index);
}
inline const ::frame_proto_mssg& clip_proto_mssg::frames(int index) const {
  // @@protoc_insertion_point(field_get:clip_proto_mssg.frames)
  return _internal_frames(index);
}
inline ::frame_proto_mssg* clip_proto_mssg::_internal_add_frames() {
  return _impl_.frames_.Add();
}
inline ::frame_proto_mssg* clip_proto_mssg::add_frames() {
  ::frame_proto_mssg* _add = _internal_add_frames();
  // @@protoc_insertion_point(field_add:clip_proto_mssg.frames)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::frame_proto_mssg >&
clip_proto_mssg::frames() const {
  // @@protoc_insertion_point(field_list:clip_proto_mssg.frames)
  return _impl_.frames_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_clip_5fproto_2eproto
