// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: font_proto.proto

#include "font_proto.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

PROTOBUF_CONSTEXPR font_proto_mssg::font_proto_mssg(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.keys_)*/{}
  , /*decltype(_impl_.fontname_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.fonttex_)*/nullptr
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct font_proto_mssgDefaultTypeInternal {
  PROTOBUF_CONSTEXPR font_proto_mssgDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~font_proto_mssgDefaultTypeInternal() {}
  union {
    font_proto_mssg _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 font_proto_mssgDefaultTypeInternal _font_proto_mssg_default_instance_;

// ===================================================================

class font_proto_mssg::_Internal {
 public:
  static const ::texture_proto_mssg& fonttex(const font_proto_mssg* msg);
};

const ::texture_proto_mssg&
font_proto_mssg::_Internal::fonttex(const font_proto_mssg* msg) {
  return *msg->_impl_.fonttex_;
}
void font_proto_mssg::clear_fonttex() {
  if (GetArenaForAllocation() == nullptr && _impl_.fonttex_ != nullptr) {
    delete _impl_.fonttex_;
  }
  _impl_.fonttex_ = nullptr;
}
void font_proto_mssg::clear_keys() {
  _impl_.keys_.Clear();
}
font_proto_mssg::font_proto_mssg(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:font_proto_mssg)
}
font_proto_mssg::font_proto_mssg(const font_proto_mssg& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite() {
  font_proto_mssg* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.keys_){from._impl_.keys_}
    , decltype(_impl_.fontname_){}
    , decltype(_impl_.fonttex_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  _impl_.fontname_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.fontname_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_fontname().empty()) {
    _this->_impl_.fontname_.Set(from._internal_fontname(), 
      _this->GetArenaForAllocation());
  }
  if (from._internal_has_fonttex()) {
    _this->_impl_.fonttex_ = new ::texture_proto_mssg(*from._impl_.fonttex_);
  }
  // @@protoc_insertion_point(copy_constructor:font_proto_mssg)
}

inline void font_proto_mssg::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.keys_){arena}
    , decltype(_impl_.fontname_){}
    , decltype(_impl_.fonttex_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.fontname_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.fontname_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

font_proto_mssg::~font_proto_mssg() {
  // @@protoc_insertion_point(destructor:font_proto_mssg)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<std::string>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void font_proto_mssg::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.keys_.~RepeatedPtrField();
  _impl_.fontname_.Destroy();
  if (this != internal_default_instance()) delete _impl_.fonttex_;
}

void font_proto_mssg::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void font_proto_mssg::Clear() {
// @@protoc_insertion_point(message_clear_start:font_proto_mssg)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.keys_.Clear();
  _impl_.fontname_.ClearToEmpty();
  if (GetArenaForAllocation() == nullptr && _impl_.fonttex_ != nullptr) {
    delete _impl_.fonttex_;
  }
  _impl_.fonttex_ = nullptr;
  _internal_metadata_.Clear<std::string>();
}

const char* font_proto_mssg::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bytes fontname = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_fontname();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .texture_proto_mssg fontTex = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_fonttex(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .key_proto_mssg keys = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_keys(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<std::string>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* font_proto_mssg::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:font_proto_mssg)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes fontname = 1;
  if (!this->_internal_fontname().empty()) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_fontname(), target);
  }

  // .texture_proto_mssg fontTex = 2;
  if (this->_internal_has_fonttex()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, _Internal::fonttex(this),
        _Internal::fonttex(this).GetCachedSize(), target, stream);
  }

  // repeated .key_proto_mssg keys = 3;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_keys_size()); i < n; i++) {
    const auto& repfield = this->_internal_keys(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(3, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:font_proto_mssg)
  return target;
}

size_t font_proto_mssg::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:font_proto_mssg)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .key_proto_mssg keys = 3;
  total_size += 1UL * this->_internal_keys_size();
  for (const auto& msg : this->_impl_.keys_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // bytes fontname = 1;
  if (!this->_internal_fontname().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_fontname());
  }

  // .texture_proto_mssg fontTex = 2;
  if (this->_internal_has_fonttex()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.fonttex_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::_pbi::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void font_proto_mssg::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::_pbi::DownCast<const font_proto_mssg*>(
      &from));
}

void font_proto_mssg::MergeFrom(const font_proto_mssg& from) {
  font_proto_mssg* const _this = this;
  // @@protoc_insertion_point(class_specific_merge_from_start:font_proto_mssg)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.keys_.MergeFrom(from._impl_.keys_);
  if (!from._internal_fontname().empty()) {
    _this->_internal_set_fontname(from._internal_fontname());
  }
  if (from._internal_has_fonttex()) {
    _this->_internal_mutable_fonttex()->::texture_proto_mssg::MergeFrom(
        from._internal_fonttex());
  }
  _this->_internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
}

void font_proto_mssg::CopyFrom(const font_proto_mssg& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:font_proto_mssg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool font_proto_mssg::IsInitialized() const {
  return true;
}

void font_proto_mssg::InternalSwap(font_proto_mssg* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.keys_.InternalSwap(&other->_impl_.keys_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.fontname_, lhs_arena,
      &other->_impl_.fontname_, rhs_arena
  );
  swap(_impl_.fonttex_, other->_impl_.fonttex_);
}

std::string font_proto_mssg::GetTypeName() const {
  return "font_proto_mssg";
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::font_proto_mssg*
Arena::CreateMaybeMessage< ::font_proto_mssg >(Arena* arena) {
  return Arena::CreateMessageInternal< ::font_proto_mssg >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
