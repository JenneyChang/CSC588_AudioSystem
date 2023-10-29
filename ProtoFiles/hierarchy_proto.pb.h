// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: hierarchy_proto.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_hierarchy_5fproto_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_hierarchy_5fproto_2eproto

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
#include "skeleton_proto.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_hierarchy_5fproto_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_hierarchy_5fproto_2eproto {
  static const uint32_t offsets[];
};
class hierarchy_proto_mssg;
struct hierarchy_proto_mssgDefaultTypeInternal;
extern hierarchy_proto_mssgDefaultTypeInternal _hierarchy_proto_mssg_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::hierarchy_proto_mssg* Arena::CreateMaybeMessage<::hierarchy_proto_mssg>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class hierarchy_proto_mssg final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:hierarchy_proto_mssg) */ {
 public:
  inline hierarchy_proto_mssg() : hierarchy_proto_mssg(nullptr) {}
  ~hierarchy_proto_mssg() override;
  explicit PROTOBUF_CONSTEXPR hierarchy_proto_mssg(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  hierarchy_proto_mssg(const hierarchy_proto_mssg& from);
  hierarchy_proto_mssg(hierarchy_proto_mssg&& from) noexcept
    : hierarchy_proto_mssg() {
    *this = ::std::move(from);
  }

  inline hierarchy_proto_mssg& operator=(const hierarchy_proto_mssg& from) {
    CopyFrom(from);
    return *this;
  }
  inline hierarchy_proto_mssg& operator=(hierarchy_proto_mssg&& from) noexcept {
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

  static const hierarchy_proto_mssg& default_instance() {
    return *internal_default_instance();
  }
  static inline const hierarchy_proto_mssg* internal_default_instance() {
    return reinterpret_cast<const hierarchy_proto_mssg*>(
               &_hierarchy_proto_mssg_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(hierarchy_proto_mssg& a, hierarchy_proto_mssg& b) {
    a.Swap(&b);
  }
  inline void Swap(hierarchy_proto_mssg* other) {
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
  void UnsafeArenaSwap(hierarchy_proto_mssg* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  hierarchy_proto_mssg* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<hierarchy_proto_mssg>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)  final;
  void CopyFrom(const hierarchy_proto_mssg& from);
  void MergeFrom(const hierarchy_proto_mssg& from);
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
  void InternalSwap(hierarchy_proto_mssg* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "hierarchy_proto_mssg";
  }
  protected:
  explicit hierarchy_proto_mssg(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kOrigListFieldNumber = 4,
    kOrderedListFieldNumber = 5,
    kCorrectedListFieldNumber = 6,
    kHierarchyTableFieldNumber = 7,
    kSkelSizeFieldNumber = 1,
    kHierarchyDepthFieldNumber = 2,
    kTableSizeFieldNumber = 3,
  };
  // repeated .skeleton_proto_mssg origList = 4;
  int origlist_size() const;
  private:
  int _internal_origlist_size() const;
  public:
  void clear_origlist();
  ::skeleton_proto_mssg* mutable_origlist(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skeleton_proto_mssg >*
      mutable_origlist();
  private:
  const ::skeleton_proto_mssg& _internal_origlist(int index) const;
  ::skeleton_proto_mssg* _internal_add_origlist();
  public:
  const ::skeleton_proto_mssg& origlist(int index) const;
  ::skeleton_proto_mssg* add_origlist();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skeleton_proto_mssg >&
      origlist() const;

  // repeated .skeleton_proto_mssg orderedList = 5;
  int orderedlist_size() const;
  private:
  int _internal_orderedlist_size() const;
  public:
  void clear_orderedlist();
  ::skeleton_proto_mssg* mutable_orderedlist(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skeleton_proto_mssg >*
      mutable_orderedlist();
  private:
  const ::skeleton_proto_mssg& _internal_orderedlist(int index) const;
  ::skeleton_proto_mssg* _internal_add_orderedlist();
  public:
  const ::skeleton_proto_mssg& orderedlist(int index) const;
  ::skeleton_proto_mssg* add_orderedlist();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skeleton_proto_mssg >&
      orderedlist() const;

  // repeated .skeleton_proto_mssg correctedList = 6;
  int correctedlist_size() const;
  private:
  int _internal_correctedlist_size() const;
  public:
  void clear_correctedlist();
  ::skeleton_proto_mssg* mutable_correctedlist(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skeleton_proto_mssg >*
      mutable_correctedlist();
  private:
  const ::skeleton_proto_mssg& _internal_correctedlist(int index) const;
  ::skeleton_proto_mssg* _internal_add_correctedlist();
  public:
  const ::skeleton_proto_mssg& correctedlist(int index) const;
  ::skeleton_proto_mssg* add_correctedlist();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skeleton_proto_mssg >&
      correctedlist() const;

  // repeated sint32 hierarchyTable = 7;
  int hierarchytable_size() const;
  private:
  int _internal_hierarchytable_size() const;
  public:
  void clear_hierarchytable();
  private:
  int32_t _internal_hierarchytable(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
      _internal_hierarchytable() const;
  void _internal_add_hierarchytable(int32_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
      _internal_mutable_hierarchytable();
  public:
  int32_t hierarchytable(int index) const;
  void set_hierarchytable(int index, int32_t value);
  void add_hierarchytable(int32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
      hierarchytable() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
      mutable_hierarchytable();

  // sint32 skelSize = 1;
  void clear_skelsize();
  int32_t skelsize() const;
  void set_skelsize(int32_t value);
  private:
  int32_t _internal_skelsize() const;
  void _internal_set_skelsize(int32_t value);
  public:

  // sint32 hierarchyDepth = 2;
  void clear_hierarchydepth();
  int32_t hierarchydepth() const;
  void set_hierarchydepth(int32_t value);
  private:
  int32_t _internal_hierarchydepth() const;
  void _internal_set_hierarchydepth(int32_t value);
  public:

  // uint32 tableSize = 3;
  void clear_tablesize();
  uint32_t tablesize() const;
  void set_tablesize(uint32_t value);
  private:
  uint32_t _internal_tablesize() const;
  void _internal_set_tablesize(uint32_t value);
  public:

  // @@protoc_insertion_point(class_scope:hierarchy_proto_mssg)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skeleton_proto_mssg > origlist_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skeleton_proto_mssg > orderedlist_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skeleton_proto_mssg > correctedlist_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t > hierarchytable_;
    mutable std::atomic<int> _hierarchytable_cached_byte_size_;
    int32_t skelsize_;
    int32_t hierarchydepth_;
    uint32_t tablesize_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_hierarchy_5fproto_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// hierarchy_proto_mssg

// sint32 skelSize = 1;
inline void hierarchy_proto_mssg::clear_skelsize() {
  _impl_.skelsize_ = 0;
}
inline int32_t hierarchy_proto_mssg::_internal_skelsize() const {
  return _impl_.skelsize_;
}
inline int32_t hierarchy_proto_mssg::skelsize() const {
  // @@protoc_insertion_point(field_get:hierarchy_proto_mssg.skelSize)
  return _internal_skelsize();
}
inline void hierarchy_proto_mssg::_internal_set_skelsize(int32_t value) {
  
  _impl_.skelsize_ = value;
}
inline void hierarchy_proto_mssg::set_skelsize(int32_t value) {
  _internal_set_skelsize(value);
  // @@protoc_insertion_point(field_set:hierarchy_proto_mssg.skelSize)
}

// sint32 hierarchyDepth = 2;
inline void hierarchy_proto_mssg::clear_hierarchydepth() {
  _impl_.hierarchydepth_ = 0;
}
inline int32_t hierarchy_proto_mssg::_internal_hierarchydepth() const {
  return _impl_.hierarchydepth_;
}
inline int32_t hierarchy_proto_mssg::hierarchydepth() const {
  // @@protoc_insertion_point(field_get:hierarchy_proto_mssg.hierarchyDepth)
  return _internal_hierarchydepth();
}
inline void hierarchy_proto_mssg::_internal_set_hierarchydepth(int32_t value) {
  
  _impl_.hierarchydepth_ = value;
}
inline void hierarchy_proto_mssg::set_hierarchydepth(int32_t value) {
  _internal_set_hierarchydepth(value);
  // @@protoc_insertion_point(field_set:hierarchy_proto_mssg.hierarchyDepth)
}

// uint32 tableSize = 3;
inline void hierarchy_proto_mssg::clear_tablesize() {
  _impl_.tablesize_ = 0u;
}
inline uint32_t hierarchy_proto_mssg::_internal_tablesize() const {
  return _impl_.tablesize_;
}
inline uint32_t hierarchy_proto_mssg::tablesize() const {
  // @@protoc_insertion_point(field_get:hierarchy_proto_mssg.tableSize)
  return _internal_tablesize();
}
inline void hierarchy_proto_mssg::_internal_set_tablesize(uint32_t value) {
  
  _impl_.tablesize_ = value;
}
inline void hierarchy_proto_mssg::set_tablesize(uint32_t value) {
  _internal_set_tablesize(value);
  // @@protoc_insertion_point(field_set:hierarchy_proto_mssg.tableSize)
}

// repeated .skeleton_proto_mssg origList = 4;
inline int hierarchy_proto_mssg::_internal_origlist_size() const {
  return _impl_.origlist_.size();
}
inline int hierarchy_proto_mssg::origlist_size() const {
  return _internal_origlist_size();
}
inline ::skeleton_proto_mssg* hierarchy_proto_mssg::mutable_origlist(int index) {
  // @@protoc_insertion_point(field_mutable:hierarchy_proto_mssg.origList)
  return _impl_.origlist_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skeleton_proto_mssg >*
hierarchy_proto_mssg::mutable_origlist() {
  // @@protoc_insertion_point(field_mutable_list:hierarchy_proto_mssg.origList)
  return &_impl_.origlist_;
}
inline const ::skeleton_proto_mssg& hierarchy_proto_mssg::_internal_origlist(int index) const {
  return _impl_.origlist_.Get(index);
}
inline const ::skeleton_proto_mssg& hierarchy_proto_mssg::origlist(int index) const {
  // @@protoc_insertion_point(field_get:hierarchy_proto_mssg.origList)
  return _internal_origlist(index);
}
inline ::skeleton_proto_mssg* hierarchy_proto_mssg::_internal_add_origlist() {
  return _impl_.origlist_.Add();
}
inline ::skeleton_proto_mssg* hierarchy_proto_mssg::add_origlist() {
  ::skeleton_proto_mssg* _add = _internal_add_origlist();
  // @@protoc_insertion_point(field_add:hierarchy_proto_mssg.origList)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skeleton_proto_mssg >&
hierarchy_proto_mssg::origlist() const {
  // @@protoc_insertion_point(field_list:hierarchy_proto_mssg.origList)
  return _impl_.origlist_;
}

// repeated .skeleton_proto_mssg orderedList = 5;
inline int hierarchy_proto_mssg::_internal_orderedlist_size() const {
  return _impl_.orderedlist_.size();
}
inline int hierarchy_proto_mssg::orderedlist_size() const {
  return _internal_orderedlist_size();
}
inline ::skeleton_proto_mssg* hierarchy_proto_mssg::mutable_orderedlist(int index) {
  // @@protoc_insertion_point(field_mutable:hierarchy_proto_mssg.orderedList)
  return _impl_.orderedlist_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skeleton_proto_mssg >*
hierarchy_proto_mssg::mutable_orderedlist() {
  // @@protoc_insertion_point(field_mutable_list:hierarchy_proto_mssg.orderedList)
  return &_impl_.orderedlist_;
}
inline const ::skeleton_proto_mssg& hierarchy_proto_mssg::_internal_orderedlist(int index) const {
  return _impl_.orderedlist_.Get(index);
}
inline const ::skeleton_proto_mssg& hierarchy_proto_mssg::orderedlist(int index) const {
  // @@protoc_insertion_point(field_get:hierarchy_proto_mssg.orderedList)
  return _internal_orderedlist(index);
}
inline ::skeleton_proto_mssg* hierarchy_proto_mssg::_internal_add_orderedlist() {
  return _impl_.orderedlist_.Add();
}
inline ::skeleton_proto_mssg* hierarchy_proto_mssg::add_orderedlist() {
  ::skeleton_proto_mssg* _add = _internal_add_orderedlist();
  // @@protoc_insertion_point(field_add:hierarchy_proto_mssg.orderedList)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skeleton_proto_mssg >&
hierarchy_proto_mssg::orderedlist() const {
  // @@protoc_insertion_point(field_list:hierarchy_proto_mssg.orderedList)
  return _impl_.orderedlist_;
}

// repeated .skeleton_proto_mssg correctedList = 6;
inline int hierarchy_proto_mssg::_internal_correctedlist_size() const {
  return _impl_.correctedlist_.size();
}
inline int hierarchy_proto_mssg::correctedlist_size() const {
  return _internal_correctedlist_size();
}
inline ::skeleton_proto_mssg* hierarchy_proto_mssg::mutable_correctedlist(int index) {
  // @@protoc_insertion_point(field_mutable:hierarchy_proto_mssg.correctedList)
  return _impl_.correctedlist_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skeleton_proto_mssg >*
hierarchy_proto_mssg::mutable_correctedlist() {
  // @@protoc_insertion_point(field_mutable_list:hierarchy_proto_mssg.correctedList)
  return &_impl_.correctedlist_;
}
inline const ::skeleton_proto_mssg& hierarchy_proto_mssg::_internal_correctedlist(int index) const {
  return _impl_.correctedlist_.Get(index);
}
inline const ::skeleton_proto_mssg& hierarchy_proto_mssg::correctedlist(int index) const {
  // @@protoc_insertion_point(field_get:hierarchy_proto_mssg.correctedList)
  return _internal_correctedlist(index);
}
inline ::skeleton_proto_mssg* hierarchy_proto_mssg::_internal_add_correctedlist() {
  return _impl_.correctedlist_.Add();
}
inline ::skeleton_proto_mssg* hierarchy_proto_mssg::add_correctedlist() {
  ::skeleton_proto_mssg* _add = _internal_add_correctedlist();
  // @@protoc_insertion_point(field_add:hierarchy_proto_mssg.correctedList)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::skeleton_proto_mssg >&
hierarchy_proto_mssg::correctedlist() const {
  // @@protoc_insertion_point(field_list:hierarchy_proto_mssg.correctedList)
  return _impl_.correctedlist_;
}

// repeated sint32 hierarchyTable = 7;
inline int hierarchy_proto_mssg::_internal_hierarchytable_size() const {
  return _impl_.hierarchytable_.size();
}
inline int hierarchy_proto_mssg::hierarchytable_size() const {
  return _internal_hierarchytable_size();
}
inline void hierarchy_proto_mssg::clear_hierarchytable() {
  _impl_.hierarchytable_.Clear();
}
inline int32_t hierarchy_proto_mssg::_internal_hierarchytable(int index) const {
  return _impl_.hierarchytable_.Get(index);
}
inline int32_t hierarchy_proto_mssg::hierarchytable(int index) const {
  // @@protoc_insertion_point(field_get:hierarchy_proto_mssg.hierarchyTable)
  return _internal_hierarchytable(index);
}
inline void hierarchy_proto_mssg::set_hierarchytable(int index, int32_t value) {
  _impl_.hierarchytable_.Set(index, value);
  // @@protoc_insertion_point(field_set:hierarchy_proto_mssg.hierarchyTable)
}
inline void hierarchy_proto_mssg::_internal_add_hierarchytable(int32_t value) {
  _impl_.hierarchytable_.Add(value);
}
inline void hierarchy_proto_mssg::add_hierarchytable(int32_t value) {
  _internal_add_hierarchytable(value);
  // @@protoc_insertion_point(field_add:hierarchy_proto_mssg.hierarchyTable)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
hierarchy_proto_mssg::_internal_hierarchytable() const {
  return _impl_.hierarchytable_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
hierarchy_proto_mssg::hierarchytable() const {
  // @@protoc_insertion_point(field_list:hierarchy_proto_mssg.hierarchyTable)
  return _internal_hierarchytable();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
hierarchy_proto_mssg::_internal_mutable_hierarchytable() {
  return &_impl_.hierarchytable_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
hierarchy_proto_mssg::mutable_hierarchytable() {
  // @@protoc_insertion_point(field_mutable_list:hierarchy_proto_mssg.hierarchyTable)
  return _internal_mutable_hierarchytable();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_hierarchy_5fproto_2eproto
