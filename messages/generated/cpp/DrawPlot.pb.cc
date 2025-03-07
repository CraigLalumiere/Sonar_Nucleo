// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DrawPlot.proto

#include "DrawPlot.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
class DrawPlotDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<DrawPlot> _instance;
} _DrawPlot_default_instance_;
static void InitDefaultsscc_info_DrawPlot_DrawPlot_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_DrawPlot_default_instance_;
    new (ptr) ::DrawPlot();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::DrawPlot::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_DrawPlot_DrawPlot_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_DrawPlot_DrawPlot_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_DrawPlot_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_DrawPlot_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_DrawPlot_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_DrawPlot_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::DrawPlot, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::DrawPlot, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::DrawPlot, plot_number_),
  PROTOBUF_FIELD_OFFSET(::DrawPlot, data_label_),
  PROTOBUF_FIELD_OFFSET(::DrawPlot, data_x_),
  PROTOBUF_FIELD_OFFSET(::DrawPlot, data_y_),
  1,
  0,
  ~0u,
  ~0u,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, sizeof(::DrawPlot)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_DrawPlot_default_instance_),
};

const char descriptor_table_protodef_DrawPlot_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016DrawPlot.proto\"[\n\010DrawPlot\022\023\n\013plot_num"
  "ber\030\001 \002(\r\022\022\n\ndata_label\030\002 \002(\t\022\022\n\006data_x\030"
  "\003 \003(\rB\002\020\001\022\022\n\006data_y\030\004 \003(\002B\002\020\001"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_DrawPlot_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_DrawPlot_2eproto_sccs[1] = {
  &scc_info_DrawPlot_DrawPlot_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_DrawPlot_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_DrawPlot_2eproto = {
  false, false, descriptor_table_protodef_DrawPlot_2eproto, "DrawPlot.proto", 109,
  &descriptor_table_DrawPlot_2eproto_once, descriptor_table_DrawPlot_2eproto_sccs, descriptor_table_DrawPlot_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_DrawPlot_2eproto::offsets,
  file_level_metadata_DrawPlot_2eproto, 1, file_level_enum_descriptors_DrawPlot_2eproto, file_level_service_descriptors_DrawPlot_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_DrawPlot_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_DrawPlot_2eproto)), true);

// ===================================================================

void DrawPlot::InitAsDefaultInstance() {
}
class DrawPlot::_Internal {
 public:
  using HasBits = decltype(std::declval<DrawPlot>()._has_bits_);
  static void set_has_plot_number(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_data_label(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x00000003) ^ 0x00000003) != 0;
  }
};

DrawPlot::DrawPlot(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  data_x_(arena),
  data_y_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:DrawPlot)
}
DrawPlot::DrawPlot(const DrawPlot& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_),
      data_x_(from.data_x_),
      data_y_(from.data_y_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  data_label_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_data_label()) {
    data_label_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_data_label(),
      GetArena());
  }
  plot_number_ = from.plot_number_;
  // @@protoc_insertion_point(copy_constructor:DrawPlot)
}

void DrawPlot::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_DrawPlot_DrawPlot_2eproto.base);
  data_label_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  plot_number_ = 0u;
}

DrawPlot::~DrawPlot() {
  // @@protoc_insertion_point(destructor:DrawPlot)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void DrawPlot::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  data_label_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void DrawPlot::ArenaDtor(void* object) {
  DrawPlot* _this = reinterpret_cast< DrawPlot* >(object);
  (void)_this;
}
void DrawPlot::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void DrawPlot::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const DrawPlot& DrawPlot::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_DrawPlot_DrawPlot_2eproto.base);
  return *internal_default_instance();
}


void DrawPlot::Clear() {
// @@protoc_insertion_point(message_clear_start:DrawPlot)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  data_x_.Clear();
  data_y_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    data_label_.ClearNonDefaultToEmpty();
  }
  plot_number_ = 0u;
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* DrawPlot::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required uint32 plot_number = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_plot_number(&has_bits);
          plot_number_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string data_label = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_data_label();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "DrawPlot.data_label");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated uint32 data_x = 3 [packed = true];
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedUInt32Parser(_internal_mutable_data_x(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24) {
          _internal_add_data_x(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated float data_y = 4 [packed = true];
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedFloatParser(_internal_mutable_data_y(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 37) {
          _internal_add_data_y(::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr));
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* DrawPlot::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:DrawPlot)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required uint32 plot_number = 1;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_plot_number(), target);
  }

  // required string data_label = 2;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_data_label().data(), static_cast<int>(this->_internal_data_label().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "DrawPlot.data_label");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_data_label(), target);
  }

  // repeated uint32 data_x = 3 [packed = true];
  {
    int byte_size = _data_x_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteUInt32Packed(
          3, _internal_data_x(), byte_size, target);
    }
  }

  // repeated float data_y = 4 [packed = true];
  if (this->_internal_data_y_size() > 0) {
    target = stream->WriteFixedPacked(4, _internal_data_y(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:DrawPlot)
  return target;
}

size_t DrawPlot::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:DrawPlot)
  size_t total_size = 0;

  if (_internal_has_data_label()) {
    // required string data_label = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_data_label());
  }

  if (_internal_has_plot_number()) {
    // required uint32 plot_number = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_plot_number());
  }

  return total_size;
}
size_t DrawPlot::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:DrawPlot)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x00000003) ^ 0x00000003) == 0) {  // All required fields are present.
    // required string data_label = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_data_label());

    // required uint32 plot_number = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_plot_number());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated uint32 data_x = 3 [packed = true];
  {
    size_t data_size = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      UInt32Size(this->data_x_);
    if (data_size > 0) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
            static_cast<::PROTOBUF_NAMESPACE_ID::int32>(data_size));
    }
    int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(data_size);
    _data_x_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  // repeated float data_y = 4 [packed = true];
  {
    unsigned int count = static_cast<unsigned int>(this->_internal_data_y_size());
    size_t data_size = 4UL * count;
    if (data_size > 0) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
            static_cast<::PROTOBUF_NAMESPACE_ID::int32>(data_size));
    }
    int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(data_size);
    _data_y_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void DrawPlot::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:DrawPlot)
  GOOGLE_DCHECK_NE(&from, this);
  const DrawPlot* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<DrawPlot>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:DrawPlot)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:DrawPlot)
    MergeFrom(*source);
  }
}

void DrawPlot::MergeFrom(const DrawPlot& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:DrawPlot)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  data_x_.MergeFrom(from.data_x_);
  data_y_.MergeFrom(from.data_y_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_data_label(from._internal_data_label());
    }
    if (cached_has_bits & 0x00000002u) {
      plot_number_ = from.plot_number_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void DrawPlot::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:DrawPlot)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DrawPlot::CopyFrom(const DrawPlot& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:DrawPlot)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DrawPlot::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_has_bits_)) return false;
  return true;
}

void DrawPlot::InternalSwap(DrawPlot* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  data_x_.InternalSwap(&other->data_x_);
  data_y_.InternalSwap(&other->data_y_);
  data_label_.Swap(&other->data_label_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  swap(plot_number_, other->plot_number_);
}

::PROTOBUF_NAMESPACE_ID::Metadata DrawPlot::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::DrawPlot* Arena::CreateMaybeMessage< ::DrawPlot >(Arena* arena) {
  return Arena::CreateMessageInternal< ::DrawPlot >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
